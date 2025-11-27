/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/27 12:44:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# ifndef FT_MAX_PHILO
#  define FT_MAX_PHILO 512
# endif

# include <stdint.h>
# include <stddef.h>

typedef struct s_philo
{
	uint32_t	index;
	uint32_t	eat_count;
	size_t		death_time;
	size_t		eat_time;
	size_t		sleep_time;
}	t_philo;

enum e_state
{
	e_sleep = 0,
	e_idle = 1,
	e_eat = 2
};

int64_t	ft_strtol(const char *str);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t length);

int		philo_init(int argc, const char **argv, t_philo *philos);
char	*ft_itoa_stack(int64_t number, char *ptr);

#endif
