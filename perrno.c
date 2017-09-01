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
