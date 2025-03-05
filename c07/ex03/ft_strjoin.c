/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:04:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/04 19:04:18 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (str[i] != 0)
        i++;
    return (i);
}

char *ft_strcat(char *dest, char *src)
{
    while (*src != 0)
    {
        *dest = *src;
        dest++;
        src++;
    }
    return (dest);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int     i;
    int     len;
    char    *cat;

    if (size <= 0)
        return ("");
    len = 0;
    i = 0;
    while (i < size)
        len += ft_strlen(strs[i++]);
    len += ft_strlen(sep) * (size - 1) + 1;
    cat = (char*) malloc(len);
    if (cat == NULL)
        return (NULL);
    i = 0;
    while (i < size)
    {
        cat = ft_strcat(cat, strs[i++]);
        if (i != size)
            cat = ft_strcat(cat, sep);
    }
    *cat = 0;
    return (cat - len + 1);
}

int main()
{
    char *sep = ", ";
    char *str1 = "ola";
    char *str2 = "meu";
    char *str3 = "nome";
    char *str4;

    char *ptr[] = {str1, str2, str3};
    str4 = ft_strjoin(3, ptr, sep);

    printf("%s", str4);
}