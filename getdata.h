#define GETDATA_H

#include <stdio.h>
#include <math.h>

int getint(void)
{
    int n, s = 0, neg = 0;
    
    while((n = getchar()) != '\n')
    {
        // Check for '-' sign
        if(n == '-' && s == 0)
            neg = 1;
        if(n >= '0' && n <= '9')
        {
            n = n - '0';
            s = s * 10 + n;
        }
    }
    
    // Check for negative number
    if(neg == 1)
        return(-s);
    else
        return(s);
}

float getfloat(void)
{
    int n, p, in = 0, c = 0, neg = 0;
    float dec = 0.0f;
    
    // Reading integer part
    // eg:- 57
    while((n = getchar()) != '.')
    {
        // Check for '-' sign
        if(n == '-' && in == 0)
            neg = 1;
            
        if(n == '\n')
        {
            // Check for negative number
            if(neg == 1)
                return(-in);
            else
                return(in);
        }
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

    // Check for negative number
    if(neg == 1)
        // Return integer part + decimal part
        // eg:- -57 + -0.27 = -57.27
        return(-in + -dec);
    else
        // Return integer part + decimal part
        // eg:- 57 + 0.27 = 57.27
        return(in + dec);
}
