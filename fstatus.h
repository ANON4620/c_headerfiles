#define _FSTATUS_H

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

void chkfstatus(FILE *fp)
{
        if(fp == NULL)
        {
                puts("Cannot open file");
                exit(1);
        }
}
