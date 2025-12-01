/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/01 14:32:10 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdint.h>
# include <stddef.h>
# include <stdatomic.h>
# include <pthread.h>
# include <unistd.h>
# include "philosophers_common.h"

typedef struct s_time
{
	long	death;
	long	eat;
	long	sleep;
}	t_time;

typedef struct s_philo
{
	const size_t		index;
	size_t				eat_count;
	const atomic_long	*time_now;
	atomic_char			*state;
	const t_time		time;
	pthread_mutex_t		*forks[2];
}	t_philo;

// 40 bytes per fork
typedef struct s_shared_cfg
{
	size_t			count;
	size_t			eat_count;
	atomic_long		time_now;
	t_time			time;					// Read by philos, written by main				
	atomic_char		state[FT_MAX_PHILO];	// Read by main, written by philos
	char			prev_state[FT_MAX_PHILO];
	pthread_mutex_t	mutex[FT_MAX_PHILO];	// Wtf, 10 kb?
	pthread_t		threads[FT_MAX_PHILO];
}	t_shared_cfg;

#endif
