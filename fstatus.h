#define _FSTATUS_H

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
                exit(1);
        }
}
