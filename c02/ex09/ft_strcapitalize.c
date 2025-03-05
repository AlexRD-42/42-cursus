/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:34:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/27 18:37:09 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char *ft_strcapitalize(char *str)
{
    int flag, cap;
    // 1 for upper, 2 for lower, 3 for other
    // TODO: remember taht numbers dont capitalize
    cap = 1;

    while (*str != 0)
    {
        if (cap == 1 && (*str >= 95 && *str <= 122))
        {
            *str = *str - 32;
            cap = 0;
        }
        else if (cap == 0 && (*str >= 65 && *str <= 90))
            *str = *str + 32;

        if (!((*str > 64 && *str < 91) || (*str > 96 && *str < 123)))
            cap = 1;

        str++;
    }

    return str;
}

int main(void)
{
    char a[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
    int flag;
    
    ft_strcapitalize(a);
    write(1, &a, sizeof(a));
    printf("\n");
}