#define _INFINP_H

#ifndef _STDIO_H
#include <stdio.h>
#endif
#ifndef _STDLIB_H
#include <stdlib.h>
#endif
#ifndef _STATUS_H
#include "status.h"
#endif

typedef char* String;

String strinp(void)
{
	FILE *fp = NULL;
	char ch, *str = NULL;
	int len = 1;

	fp = fopen("temp.tmp", "w+");
	chkfstatus(fp, 8, "temp.tmp");
	while(1)
	{
		ch = fgetc(stdin);
		if(ch == '\n')
			break;
		fputc(ch, fp);
		len++;
	}
	
	// allocating memory
	str = (String) malloc(len * sizeof(char));
	
	// set pointer to the beginning
	fseek(fp, 0, SEEK_SET);

	for(int i = 0; i < len - 1; i++)
		str[i] = fgetc(fp);
	str[len - 1] = '\0';
	fclose(fp);

	remove("temp.tmp");

	return str;
}
