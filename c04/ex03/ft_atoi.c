/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:14:45 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/04 13:36:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (*str != 0)
    {
        str++;
        i++;
    }
    return i;
}

int ft_pow(int num, int exp)
{
    int base = num;
    if (exp == 0)
        return 1;
    else
        while (exp > 1)
        {
            num = num * base;
            exp--;
        }
    return num;
}

int ft_str2num(char *str)
{
    int strLength;
    int value;
    int i;

    i = 0;
    strLength = ft_strlen(str);
    
    while (i < strLength)
    {
        value = value + (str[strLength-i-1] - '0') * ft_pow(10, i);
        i++;
    }

    return value;
}

int main(void)
{
    int a = 2;
    int b = 10;
    char str[] = "123456";
    printf ("%d\n", ft_str2num(str));
    // printf("%d", ft_pow(a, b));
}