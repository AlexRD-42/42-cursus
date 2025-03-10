/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:09:03 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 00:09:03 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_STRING_H
#define FT_STRING_H

int     ft_strlen(char *str);
int     ft_atoi(char *str);
char    *ft_strncpy(char *src, unsigned int n);
char    *ft_strncat(char *dest, char *src, int n);
void    ft_printstr(char *str, int print_flag);

#endif