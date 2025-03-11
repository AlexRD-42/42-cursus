/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:04:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/11 11:15:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i;
		
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strcatn(char *dest, char *src, int *j)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[*j] = src[i];
		i++;
		*j += 1;
	}
	dest[*j] = 0;
	return (dest);
}

char	*ft_emptystr(void)
{
	char	*str;

	str = (char *) malloc(1);
	str[0] = 0;
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*cat;
	int		i;
	int		j;
	int		len;

	if (size <= 0)
		return (ft_emptystr());
	len = 0;
	i = -1;
	while (++i < size)
		len += ft_strlen(strs[i]);
	cat = (char*) malloc((len + 1) + ft_strlen(sep) * (size - 1));
	if (cat == NULL)
		return (NULL);
	j = 0;
	i = -1;
	while (++i < size)
	{
		cat = ft_strcatn(cat, strs[i], &j);
		if (i != size - 1)
			cat = ft_strcatn(cat, sep, &j);
	}
	return (cat);
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

    printf("%s:\t(%d letters)", str4, ft_strlen(str4));
	if (str4[ft_strlen(str4)] != 0)
		printf("Error");
}