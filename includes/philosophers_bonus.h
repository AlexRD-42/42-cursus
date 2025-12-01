/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/01 17:27:42 by adeimlin         ###   ########.fr       */
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

typedef struct s_philo
{
	const size_t	index;
	t_params		params;
	atomic_long		*time_now;
	atomic_uchar	*state;
}	t_philo;

typedef struct s_thread_cfg
{
	const size_t	index;
	t_params		params;
	atomic_long		time_now;
	atomic_uchar	state;
}	t_thread_cfg;

// 40 bytes per fork
typedef struct s_sim_cfg
{
	t_params	params;
	atomic_long	time_now;
}	t_sim_cfg;

#endif
