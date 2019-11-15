
/*
 * Copyright Andrew Sharp andy@tigerand.com 2018-2019, All Rights Reserved.
 */

/*
 * both these functions are multi-thread safe (MT-Safe)
 */

/*
 * return a pointer to a static string that is the errno mnemonic
 */
 const char *
perrno(int erg)
{
	if (_ernames_unitialized) {
		_init_ernames();
	}
	if (abs(erg) <= N_ERNAMES) {
		return (const char *)ernames[abs(erg)];
	} else {
		return NULL;
	}
}

/*
 * return a pointer to a static string that is message string
 */
 const char *
strerrno(int erg)
{
	if (_erstrings_unitialized) {
		_init_erstrings();
	}
	if (abs(erg) <= N_ERSTRINGS) {
		return (const char *)erstrings[abs(erg)];
	} else {
		return NULL;
	}
}
