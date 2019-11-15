#!/bin/bash

COPYRIGHT="Copyright Andrew Sharp andy@tigerand.com 2018-2019, All Rights Reserved."

_max()
{
	if [ "$1" -gt "$2" ] ; then
		echo "$1"
	else
		echo "$2"
	fi
}

ARCH_ENOFILE=`dpkg-architecture -q DEB_HOST_GNU_TYPE`/bits/errno.h

ENO_FLIST="errno.h bits/errno.h asm-generic/errno-base.h asm-generic/errno.h $ARCH_ENOFILE"

# some systems don't have a symlink from ../bits to ../ARCH/bits
if [ ! -d /usr/include/bits ] ; then
	ENO_FLIST=`echo $ENO_FLIST | sed 's% bits/errno.h%%'`
fi

declare -A ERNAMES
declare -A ERSTRS

declare -i T SN SS

SN=1
SS=1

# isolate the directory where this code resides
PDIR=`dirname $0`


cat >perrno.h <<COPYRIGHTMSG
/*
 * $COPYRIGHT
 */

COPYRIGHTMSG


# grep the mnemonics out of the header files and into our code

egrep '#[[:space:]]*define[[:space:]]+E' /usr/include/${ENO_FLIST// / /usr/include/} |
	sed 's/^.*define[[:space:]]\+//'  |
	while read EMAC ENO RESTO ; do
		ERNAMES[$ENO]=$EMAC
		T=$ENO
		SN=`_max $T $SN`
		if [ "$RESTO" ] ; then
			ERSTRS[$ENO]="${RESTO#* }"
			ERSTRS[$ENO]="${ERSTRS[$ENO]% *}"
			SS=`_max $T $SS`
		fi
		# just write the whole file anew for each friggin definition, because
		# while is executed in a subshell
		echo "static int _ernames_unitialized = 1;" >>perrno.h
		echo "static int _erstrings_unitialized = 1;" >>perrno.h
		echo "#define N_ERNAMES ${SN}" >>perrno.h
		echo "#define N_ERSTRINGS ${SS}" >>perrno.h
		echo "static char *ernames[N_ERNAMES + 1];" >>perrno.h
		echo "static char *erstrings[N_ERSTRINGS + 1];" >>perrno.h
		echo >>perrno.h

		# do the macros
		echo -e " static void\n_init_ernames(void)\n{" >perrno-name-initializers
		# as opposed to the integer defined names
		# put the macro defined macro names at the perginning
		X=`for I in ${!ERNAMES[*]} ; do
			echo "$I"
		done | sort -n`
		for I in $X ; do
			echo -e "\ternames[$I] = \"${ERNAMES[$I]}\";" # >>perrno.h
		done >>perrno-name-initializers
		echo -e "\t_ernames_unitialized = 0;\n}" >>perrno-name-initializers

		# do the strings
		echo -e "\n static void\n_init_erstrings(void)\n{" >perrno-string-initializers
		# put the macro defined strings at the end
		X=`for I in ${!ERSTRS[*]} ; do
			echo "$I"
		done | sort -d`
		for I in $X ; do
			echo -e "\terstrings[$I] = \"${ERSTRS[$I]}\";" # >>perrno.h
		done >>perrno-string-initializers
		echo -e "\t_erstrings_unitialized = 0;\n}" >>perrno-string-initializers
	done
# >edefines-file

cat perrno-name-initializers perrno-string-initializers >> perrno.h
rm -f edefines-file perrno-name-initializers perrno-string-initializers

echo >> perrno.h
cat "$PDIR/perrno.c" >> perrno.h

