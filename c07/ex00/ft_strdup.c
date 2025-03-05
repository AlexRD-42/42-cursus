/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:45:55 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 20:53:50 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strdup(char *src)
{
    char    *str;
    int     len;
    int     i;

    i = 0;
    while (src[i] != 0)
        i++;
    len = i + 1;
    str = (char*) malloc(len);
    if (str == NULL)
        return (NULL);
    i = 0;
    while (i < len - 1)
    {
        str[i] = src[i];
        i++;
    }
    str[i] = 0;
    return (str);
}

int main()
{
    char a[] = "string 1";
    char *b;

    b = ft_strdup(a);

    printf("%s", b);
}