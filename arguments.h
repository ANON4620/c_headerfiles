#define _ARGS_H

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

void chkargs(int argc, int argp)
{
	++argp;
	if(argc < argp)
	{
		puts("Too few arguments.");
		exit(0);
	}
	if(argc > argp)
	{
		puts("Too many arguments.");
		exit(0);
	}
}
