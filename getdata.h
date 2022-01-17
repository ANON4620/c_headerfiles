int getint(void)
{
    int n, s = 0;
    while((n = getchar()) != '\n')
    {
        n = n - '0';
        s = s * 10 + n;
    }
    
    return(s);
}
