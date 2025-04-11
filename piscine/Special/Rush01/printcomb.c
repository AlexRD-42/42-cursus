/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:14:07 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/01 18:39:55 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_print_str(int n, char *str, int flag)
{
	char num;
	char spc;
	n--;
	spc = ',';

	while (n >= 0)
	{
		num = str[n] + '0';
		n--;
		write(1, &num, 1);
	}

	if (flag)
		write(1, &spc, 1);
}

void ft_print_combn(int n)
{
	char comb[n];
	char results[24][n];
    int i = 0, j = 0, k = 0;

	while (i < n)
		comb[i++] = 1;
	i = 0;
	while (!((comb[n - 1] == 4) && (comb[0] == 4)))
	{
		while (comb[i] == 4 && i < n)
			i++;
		comb[i]++;
		while (i>0)
            comb[i-- -1] = 1;

        k = 0;
        while (k < n)
        {
            if (comb[k] != comb[k+1])
                results[j][k] = comb[k];
        }
		ft_print_str(n, &comb[0], 1);
	}
}

int main(void)
{
    int i = 0, j = 0;
    int n = 3;

    ft_print_combn(3);


    // int fact = 1;
    // for (i=n; i>0 ; i--)
    //     fact = i * fact;

    // int array[fact][n];

    
    // int array[n];

    // for (i=0;i<n;i++)
    //     array[i] = i + 1;

    // for (i=0;i<n;i++)
    // {
    //     for (int j=0;j<n;j++)
    //     {
            
    //     }
    // }

    // for (i=0; i<n;i++)
    //     printf("%d, ", array[i]);

}