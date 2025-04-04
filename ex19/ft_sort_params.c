/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:06:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/03 15:11:10 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_sortstr(char **str_array, int n)
{
	char	*temp;
	int		i;
	int		j;

	i = 1;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_strcmp(str_array[i], str_array[j]) > 0)
			{
				temp = str_array[i];
				str_array[i] = str_array[j];
				str_array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 1)
	{
		ft_putchar('\n');
		return (0);
	}
	ft_sortstr(argv, argc);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
