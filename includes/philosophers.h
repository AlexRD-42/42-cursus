/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/01 14:28:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdint.h>
# include <stddef.h>
# include <stdatomic.h>
# include <pthread.h>
# include <unistd.h>
# include "philosophers_common.h"

typedef struct s_philo
{
	const size_t		index;
	t_params			params;
	const atomic_long	*time_now;
	atomic_char			*state;
	pthread_mutex_t		*forks[2];
}	t_philo;

// 40 bytes per fork
typedef struct s_sim_cfg
{
	t_params		params;
	atomic_long		time_now;
	atomic_char		state[FT_MAX_PHILO];	// Read by main, written by philos
	char			prev_state[FT_MAX_PHILO];
	pthread_mutex_t	mutex[FT_MAX_PHILO];	// Wtf, 10 kb?
	pthread_t		threads[FT_MAX_PHILO];
}	t_sim_cfg;

int			sim_init(int argc, const char **argv, t_sim_cfg *philo_cfg);
void		*philo_start(void *varg);

#endif
