#include <unistd.h>
#include <stdio.h>

int ft_str_is_uppercase(char *str)
{
    int flag;
    
    flag = 1;
    while (*str != 0 && flag == 1)
    {
        if (!(*str > 64 && *str < 91))
            flag = 0;
        str++;
    }

    return flag;
}

int main(void)
{
    char a[] = "AAAA";
    int flag;
    
    flag = ft_str_is_uppercase(a);
    printf("%d\n", flag);
}