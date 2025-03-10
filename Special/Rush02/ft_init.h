/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:21:57 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 00:21:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_INIT_H
#define FT_INIT_H

char    *zero_pad(char *str, int n);
char    *read_file(int *totalsize, char *filename);
void    ft_free(char ***dict, char **input, char **str);
void	ft_start(char *num, char **dict);

#endif