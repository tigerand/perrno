static int _ernames_unitialized = 1;
static int _erstrings_unitialized = 1;
#define N_ERNAMES 133
#define N_ERSTRINGS 133
static char *ernames[N_ERNAMES + 1];
static char *erstrings[N_ERSTRINGS + 1];

 static void
_init_ernames(void)
{
	ernames[EAGAIN] = "EWOULDBLOCK";
	ernames[EDEADLK] = "EDEADLOCK";
	ernames[EOPNOTSUPP] = "ENOTSUP";
	ernames[1] = "EPERM";
	ernames[2] = "ENOENT";
	ernames[3] = "ESRCH";
	ernames[4] = "EINTR";
	ernames[5] = "EIO";
	ernames[6] = "ENXIO";
	ernames[7] = "E2BIG";
	ernames[8] = "ENOEXEC";
	ernames[9] = "EBADF";
	ernames[10] = "ECHILD";
	ernames[11] = "EAGAIN";
	ernames[12] = "ENOMEM";
	ernames[13] = "EACCES";
	ernames[14] = "EFAULT";
	ernames[15] = "ENOTBLK";
	ernames[16] = "EBUSY";
	ernames[17] = "EEXIST";
	ernames[18] = "EXDEV";
	ernames[19] = "ENODEV";
	ernames[20] = "ENOTDIR";
	ernames[21] = "EISDIR";
	ernames[22] = "EINVAL";
	ernames[23] = "ENFILE";
	ernames[24] = "EMFILE";
	ernames[25] = "ENOTTY";
	ernames[26] = "ETXTBSY";
	ernames[27] = "EFBIG";
	ernames[28] = "ENOSPC";
	ernames[29] = "ESPIPE";
	ernames[30] = "EROFS";
	ernames[31] = "EMLINK";
	ernames[32] = "EPIPE";
	ernames[33] = "EDOM";
	ernames[34] = "ERANGE";
	ernames[35] = "EDEADLK";
	ernames[36] = "ENAMETOOLONG";
	ernames[37] = "ENOLCK";
	ernames[38] = "ENOSYS";
	ernames[39] = "ENOTEMPTY";
	ernames[40] = "ELOOP";
	ernames[42] = "ENOMSG";
	ernames[43] = "EIDRM";
	ernames[44] = "ECHRNG";
	ernames[45] = "EL2NSYNC";
	ernames[46] = "EL3HLT";
	ernames[47] = "EL3RST";
	ernames[48] = "ELNRNG";
	ernames[49] = "EUNATCH";
	ernames[50] = "ENOCSI";
	ernames[51] = "EL2HLT";
	ernames[52] = "EBADE";
	ernames[53] = "EBADR";
	ernames[54] = "EXFULL";
	ernames[55] = "ENOANO";
	ernames[56] = "EBADRQC";
	ernames[57] = "EBADSLT";
	ernames[59] = "EBFONT";
	ernames[60] = "ENOSTR";
	ernames[61] = "ENODATA";
	ernames[62] = "ETIME";
	ernames[63] = "ENOSR";
	ernames[64] = "ENONET";
	ernames[65] = "ENOPKG";
	ernames[66] = "EREMOTE";
	ernames[67] = "ENOLINK";
	ernames[68] = "EADV";
	ernames[69] = "ESRMNT";
	ernames[70] = "ECOMM";
	ernames[71] = "EPROTO";
	ernames[72] = "EMULTIHOP";
	ernames[73] = "EDOTDOT";
	ernames[74] = "EBADMSG";
	ernames[75] = "EOVERFLOW";
	ernames[76] = "ENOTUNIQ";
	ernames[77] = "EBADFD";
	ernames[78] = "EREMCHG";
	ernames[79] = "ELIBACC";
	ernames[80] = "ELIBBAD";
	ernames[81] = "ELIBSCN";
	ernames[82] = "ELIBMAX";
	ernames[83] = "ELIBEXEC";
	ernames[84] = "EILSEQ";
	ernames[85] = "ERESTART";
	ernames[86] = "ESTRPIPE";
	ernames[87] = "EUSERS";
	ernames[88] = "ENOTSOCK";
	ernames[89] = "EDESTADDRREQ";
	ernames[90] = "EMSGSIZE";
	ernames[91] = "EPROTOTYPE";
	ernames[92] = "ENOPROTOOPT";
	ernames[93] = "EPROTONOSUPPORT";
	ernames[94] = "ESOCKTNOSUPPORT";
	ernames[95] = "EOPNOTSUPP";
	ernames[96] = "EPFNOSUPPORT";
	ernames[97] = "EAFNOSUPPORT";
	ernames[98] = "EADDRINUSE";
	ernames[99] = "EADDRNOTAVAIL";
	ernames[100] = "ENETDOWN";
	ernames[101] = "ENETUNREACH";
	ernames[102] = "ENETRESET";
	ernames[103] = "ECONNABORTED";
	ernames[104] = "ECONNRESET";
	ernames[105] = "ENOBUFS";
	ernames[106] = "EISCONN";
	ernames[107] = "ENOTCONN";
	ernames[108] = "ESHUTDOWN";
	ernames[109] = "ETOOMANYREFS";
	ernames[110] = "ETIMEDOUT";
	ernames[111] = "ECONNREFUSED";
	ernames[112] = "EHOSTDOWN";
	ernames[113] = "EHOSTUNREACH";
	ernames[114] = "EALREADY";
	ernames[115] = "EINPROGRESS";
	ernames[116] = "ESTALE";
	ernames[117] = "EUCLEAN";
	ernames[118] = "ENOTNAM";
	ernames[119] = "ENAVAIL";
	ernames[120] = "EISNAM";
	ernames[121] = "EREMOTEIO";
	ernames[122] = "EDQUOT";
	ernames[123] = "ENOMEDIUM";
	ernames[124] = "EMEDIUMTYPE";
	ernames[125] = "ECANCELED";
	ernames[126] = "ENOKEY";
	ernames[127] = "EKEYEXPIRED";
	ernames[128] = "EKEYREVOKED";
	ernames[129] = "EKEYREJECTED";
	ernames[130] = "EOWNERDEAD";
	ernames[131] = "ENOTRECOVERABLE";
	ernames[132] = "ERFKILL";
	ernames[133] = "EHWPOISON";
	_ernames_unitialized = 0;
}

 static void
_init_erstrings(void)
{
	erstrings[1] = "Operation not permitted";
	erstrings[10] = "No child processes";
	erstrings[100] = "Network is down";
	erstrings[101] = "Network is unreachable";
	erstrings[102] = "Network dropped connection because of reset";
	erstrings[103] = "Software caused connection abort";
	erstrings[104] = "Connection reset by peer";
	erstrings[105] = "No buffer space available";
	erstrings[106] = "Transport endpoint is already connected";
	erstrings[107] = "Transport endpoint is not connected";
	erstrings[108] = "Cannot send after transport endpoint shutdown";
	erstrings[109] = "Too many references: cannot splice";
	erstrings[11] = "Try again";
	erstrings[110] = "Connection timed out";
	erstrings[111] = "Connection refused";
	erstrings[112] = "Host is down";
	erstrings[113] = "No route to host";
	erstrings[114] = "Operation already in progress";
	erstrings[115] = "Operation now in progress";
	erstrings[116] = "Stale file handle";
	erstrings[117] = "Structure needs cleaning";
	erstrings[118] = "Not a XENIX named type file";
	erstrings[119] = "No XENIX semaphores available";
	erstrings[12] = "Out of memory";
	erstrings[120] = "Is a named type file";
	erstrings[121] = "Remote I/O error";
	erstrings[122] = "Quota exceeded";
	erstrings[123] = "No medium found";
	erstrings[124] = "Wrong medium type";
	erstrings[125] = "Operation Canceled";
	erstrings[126] = "Required key not available";
	erstrings[127] = "Key has expired";
	erstrings[128] = "Key has been revoked";
	erstrings[129] = "Key was rejected by service";
	erstrings[13] = "Permission denied";
	erstrings[130] = "Owner died";
	erstrings[131] = "State not recoverable";
	erstrings[132] = "Operation not possible due to RF-kill";
	erstrings[133] = "Memory page has hardware error";
	erstrings[14] = "Bad address";
	erstrings[15] = "Block device required";
	erstrings[16] = "Device or resource busy";
	erstrings[17] = "File exists";
	erstrings[18] = "Cross-device link";
	erstrings[19] = "No such device";
	erstrings[2] = "No such file or directory";
	erstrings[20] = "Not a directory";
	erstrings[21] = "Is a directory";
	erstrings[22] = "Invalid argument";
	erstrings[23] = "File table overflow";
	erstrings[24] = "Too many open files";
	erstrings[25] = "Not a typewriter";
	erstrings[26] = "Text file busy";
	erstrings[27] = "File too large";
	erstrings[28] = "No space left on device";
	erstrings[29] = "Illegal seek";
	erstrings[3] = "No such process";
	erstrings[30] = "Read-only file system";
	erstrings[31] = "Too many links";
	erstrings[32] = "Broken pipe";
	erstrings[33] = "Math argument out of domain of function. ";
	erstrings[34] = "Math result not representable. ";
	erstrings[35] = "Resource deadlock would occur";
	erstrings[36] = "File name too long";
	erstrings[37] = "No record locks available";
	erstrings[38] = "Invalid system call number";
	erstrings[39] = "Directory not empty";
	erstrings[4] = "Interrupted system call";
	erstrings[40] = "Too many symbolic links encountered";
	erstrings[42] = "No message of desired type";
	erstrings[43] = "Identifier removed";
	erstrings[44] = "Channel number out of range";
	erstrings[45] = "Level 2 not synchronized";
	erstrings[46] = "Level 3 halted";
	erstrings[47] = "Level 3 reset";
	erstrings[48] = "Link number out of range";
	erstrings[49] = "Protocol driver not attached";
	erstrings[5] = "I/O error";
	erstrings[50] = "No CSI structure available";
	erstrings[51] = "Level 2 halted";
	erstrings[52] = "Invalid exchange";
	erstrings[53] = "Invalid request descriptor";
	erstrings[54] = "Exchange full";
	erstrings[55] = "No anode";
	erstrings[56] = "Invalid request code";
	erstrings[57] = "Invalid slot";
	erstrings[59] = "Bad font file format";
	erstrings[6] = "No such device or address";
	erstrings[60] = "Device not a stream";
	erstrings[61] = "No data available";
	erstrings[62] = "Timer expired";
	erstrings[63] = "Out of streams resources";
	erstrings[64] = "Machine is not on the network";
	erstrings[65] = "Package not installed";
	erstrings[66] = "Object is remote";
	erstrings[67] = "Link has been severed";
	erstrings[68] = "Advertise error";
	erstrings[69] = "Srmount error";
	erstrings[7] = "Argument list too long";
	erstrings[70] = "Communication error on send";
	erstrings[71] = "Protocol error";
	erstrings[72] = "Multihop attempted";
	erstrings[73] = "RFS specific error";
	erstrings[74] = "Not a data message";
	erstrings[75] = "Value too large for defined data type";
	erstrings[76] = "Name not unique on network";
	erstrings[77] = "File descriptor in bad state";
	erstrings[78] = "Remote address changed";
	erstrings[79] = "Can not access a needed shared library";
	erstrings[8] = "Exec format error";
	erstrings[80] = "Accessing a corrupted shared library";
	erstrings[81] = ".lib section in a.out corrupted";
	erstrings[82] = "Attempting to link in too many shared libraries";
	erstrings[83] = "Cannot exec a shared library directly";
	erstrings[84] = "Illegal byte sequence. ";
	erstrings[85] = "Interrupted system call should be restarted";
	erstrings[86] = "Streams pipe error";
	erstrings[87] = "Too many users";
	erstrings[88] = "Socket operation on non-socket";
	erstrings[89] = "Destination address required";
	erstrings[9] = "Bad file number";
	erstrings[90] = "Message too long";
	erstrings[91] = "Protocol wrong type for socket";
	erstrings[92] = "Protocol not available";
	erstrings[93] = "Protocol not supported";
	erstrings[94] = "Socket type not supported";
	erstrings[95] = "Operation not supported on transport endpoint";
	erstrings[96] = "Protocol family not supported";
	erstrings[97] = "Address family not supported by protocol";
	erstrings[98] = "Address already in use";
	erstrings[99] = "Cannot assign requested address";
	erstrings[EAGAIN] = "Operation would block";
	_erstrings_unitialized = 0;
}

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
