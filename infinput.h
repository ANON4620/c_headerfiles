#define _INFINPUT_H

#ifndef _STDIO_H
#include <stdio.h>
#endif
#ifndef _STDLIB_H
#include <stdlib.h>
#endif
#ifndef _CONIO_H
#include "conio.h"
#endif
#ifndef _STATUS_H
#include "status.h"
#endif

char * strinp(void)
{
	FILE *fp = NULL;
	char ch, *str = NULL;
	int len = 1;

	fp = fopen("temp.tmp", "w+");
	chkfstatus(fp, 8, "temp.tmp");
	while(1)
	{
		ch = getch();
		if(ch == '\n')
			break;
		fputc(ch, fp);
		printf("%c", ch);
		len++;
	}
	
	str = (char *) malloc(len * sizeof(char));
	fseek(fp, 0, SEEK_SET);
	for(int i = 0; i < len - 1; i++)
		str[i] = fgetc(fp);
	str[len - 1] = '\0';
	fclose(fp);

	system("rm temp.tmp");
	printf("\n");

	return str;
}
