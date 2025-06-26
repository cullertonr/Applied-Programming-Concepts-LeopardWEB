#include <iostream>
#include "sqlite3.h"
#include "Myfunc.h"
#include <string>
#include <stdio.h>

using namespace std;

static int callback(void* data, int argc, char** argv, char** azcolname)
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azcolname[i], argv[i] ? argv[i] : "null");
	}

	printf("\n");

	return 0;
}
