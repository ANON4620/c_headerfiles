#include <stdio.h>

int getint(void)
{
    int n, s = 0;
    _Bool neg = 0;

    while( (n = getchar()) )
    {
        if(n == '\n' || n == ' ')
                break;

        // Check for '-' sign
        if(n == '-' && s == 0)
            neg = 1;
        else if(n >= '0' && n <= '9')
        {
            n = n - '0';
            s = s * 10 + n;
        }
    }                                                      
    // Check for negative number
    if(neg)
        return(-s);
    else
        return(s);
}

float getfloat(void)
{
    int n, in = 0, c = 0;
    float dec = 0.0f;
    _Bool neg = 0;

    // Reading integer part
    // eg:- 57
    while( (n = getchar()) != '.' )
    {
        if(n == '\n' || n == ' ')
        {
            // Check for negative number
            if(neg)
                return(-in);
            else
                return(in);
        }

        // Check for '-' sign
        if(n == '-' && in == 0)
            neg = 1;
        else if(n >= '0' && n <= '9')
        {
            n = n - '0';
            in = in * 10 + n;
        }
    }

    // Reading decimal part as integer
    // eg:- 27
    while( (n = getchar()) )
    {
        if(n == '\n' || n == ' ')
                break;

        if(n >= '0' && n <= '9')
        {
            n = n - '0';
            dec = dec * 10 + n;
            ++c;
        }
    }

    // Convert decimal part(read as integer) to its decimal value
    // eg:- 27 to 0.27
    for(int i = 1; i <= c; i++)
        dec = dec / 10;

    // Check for negative number
    if(neg)
        // Return integer part + decimal part
        // eg:- -57 + -0.27 = -57.27
        return(-in + -dec);
    else
        // Return integer part + decimal part
        // eg:- 57 + 0.27 = 57.27
        return(in + dec);
}
