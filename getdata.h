#define GETDATA_H

#ifndef _STDIO_H
#include <stdio.h>
#endif
#ifndef _MATH_H
#include <math.h>
#endif

int getint(void)
{
    int n, s = 0;
    while((n = getchar()) != '\n')
    {
        if(n >= '0' && n <= '9')
        {
            n = n - '0';
            s = s * 10 + n;
        }
    }

    return(s);
}

float getfloat(void)
{
    int n, p, in = 0, c = 0;
    float dec = 0.0f;
    
    // Reading integer part
    // eg:- 57
    while((n = getchar()) != '.')
    {
        if(n == '\n')
            return(in);
        else if(n >= '0' && n <= '9')
        {
            n = n - '0';
            in = in * 10 + n;
        }
    }
    
    // Reading decimal part as integer
    // eg:- 27
    while((n = getchar()) != '\n')
    {
        if(n >= '0' && n <= '9')
        {
            n = n - '0';
            dec = dec * 10 + n;
            ++c;
        }
    }
    
    // Convert decimal part(read as integer) to its decimal value
    // eg:- 27 to 0.27
    p = (int) pow(10, c);
    dec = dec / p;
    
    // Return integer part + decimal part
    // eg:- 57 + 0.27 = 57.27
    return(in + dec);
}
