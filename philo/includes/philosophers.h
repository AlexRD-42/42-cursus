/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/27 15:10:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# ifndef FT_MAX_PHILO
#  define FT_MAX_PHILO 256
# endif

# include <stdint.h>
# include <stddef.h>

typedef struct s_pcfg
{
	size_t	count;
	size_t	eat_count;
	size_t	death_time;
	size_t	eat_time;
	size_t	sleep_time;
	void	*mutex;
	void	*threads;
	void	*philos;
}	t_philo_cfg;

typedef struct s_philo
{
	size_t		index;
	t_philo_cfg	*cfg;
}	t_philo;

enum e_philo_state
{
	e_sleep = 0,
	e_idle = 1,
	e_eat = 2
};

int64_t	ft_strtol(const char *str);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t length);
void	*philo_init(int argc, const char **argv);
char	*ft_itoa_stack(int64_t number, char *ptr);

#endif
