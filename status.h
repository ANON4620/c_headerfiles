#define _STATUS_H

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif


void chkfstatus(FILE *fp, char fname[80])
{
        if(fp == NULL)
        {
                printf("Cannot open file: %s\n", fname);
                exit(0);
        }
}

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
