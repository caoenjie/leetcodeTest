#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convert(char *s, int r)
{
    if (r == 1)
        return s;
    size_t n = strlen(s);

    char *a = (char *)malloc(sizeof(char) * (n + 1));
    char *p = a;
    int i = 0, j, k;
    for (i = 0; i < n; i += (2 * r - 2))
    {
        *(p++) = s[i];
    }
    printf("%s\n", a);
    for (i = 1; i < r - 1; i++)
    {
        k = i;
        for (j = 0; k < n; j++)
        {
            *(p++) = s[k];
            if (j % 2 == 0)
                k = k + (2 * r - 2 - 2 * i);
            else
                k = k + (2 * i);
        }
    }

    for (i = r - 1; i < n; i += 2 * r - 2)
    {
        *(p++) = s[i];
    }

    *p = '\0';

    return a;
}

int main()
{
    char str[] = "PAYPALISHIRING"; //PINALSIGYAHRPI
    char *a = convert(str, 4);
    printf("%s\n",a);
    
    return 0;
}