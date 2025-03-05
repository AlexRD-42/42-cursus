/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:15:33 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/27 12:17:11 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_str_is_lowercase(char *str)
{
    int flag;
    
    flag = 1;
    while (*str != 0 && flag == 1)
    {
        if (!(*str > 96 && *str < 123))
            flag = 0;
        str++;
    }

    return flag;
}

int main(void)
{
    char a[] = "";
    int flag;
    
    flag = ft_str_is_lowercase(a);
    printf("%d\n", flag);
}