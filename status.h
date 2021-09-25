#define _STATUS_H

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif


void chkfstatus(FILE *fp, long len, char fname[len])
{
        if(fp == NULL)
        {
                printf("Cannot open file: %s\n", fname);
                exit(0);
        }
}

void chkargs(int argc, int n)
{
	n++;
        if(argc < n)
        {
                puts("Too few arguments.");
                exit(0);
        }
        if(argc > n)
        {
                puts("Too many arguments.");
                exit(0);
        }
}

void chkmem(void *address)
{
	if(address == NULL)
	{
		puts("Out of memory!");
		exit(0);
	}
}
