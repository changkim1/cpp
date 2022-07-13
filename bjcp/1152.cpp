#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000002] = "";
    int i, len = 0;
    int count = 1;

    fgets(str, sizeof(str), stdin);
    len = strlen(str);
    len--;
    
    for (i = 1; i < len; i++)
	{
        if (str[i] == 32 && str[i - 1] != 32)
		{
            count++;
        }
    }

    if (str[len - 1] == 32)
	{
        count--;
    }

    printf("%d \n", count);

    return 0;
}