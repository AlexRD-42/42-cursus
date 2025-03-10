/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:13:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 00:13:43 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PARSE_H
#define FT_PARSE_H

char    *parse_digit(char *str, int *i, int *flag);
char    *parse_text(char *str, int *i, int *flag);
char    **parse_input(char *str, int totalsize);
void    parse_line(char *str, char **num_str, char **text_str, int *index);
int     index_lookup(char *num_str);

#endif