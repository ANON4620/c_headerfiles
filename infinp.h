#define _INFINP_H

#ifndef _STDIO_H
#include <stdio.h>
#endif
#ifndef _STDLIB_H
#include <stdlib.h>
#endif
#ifndef _STDDEF_H
#include <stddef.h>
#endif
#ifndef _STDBOOL_H
#include <stdbool.h>
#endif
#ifndef _STATUS_H
#include "status.h"
#endif

typedef char* String;

void strinp(String* str)
{
	char ch;
	int len = 1;

	while(1)
	{
		ch = fgetc(stdin);
		if(ch == '\n')
			break;
		*str = (String) realloc(*str, len * sizeof(
char));
		chkmem(*str);
		*(*str + (len - 1)) = ch;
		len++;
	}
	*(*str + (len - 1)) = '\0';
}
