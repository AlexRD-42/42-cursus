/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/22 16:56:07 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdint.h>
# include <stddef.h>
# include <unistd.h>

typedef enum e_state
{
	st_sleep = 0,
	st_idle = 1,
	st_eat = 2
}	t_state;

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t length);
int64_t	ft_atoi(const char *str);

#endif
