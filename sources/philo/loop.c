/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:18:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/01 14:28:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <threads.h>
#include <unistd.h>
#include <stdatomic.h>
#include <sys/time.h>
#include <pthread.h>
#include "philosophers.h"

static inline
void	stt_update_clock(long delay, t_philo *philo)
{
	static thread_local long	cur_time = 0;
	long						dt;
	long						prev_time;

	while (delay >= 0)
	{
		prev_time = cur_time;
		while (cur_time == prev_time)
		{
			cur_time = *philo->time_now;
			usleep(FT_UPDATE_INTERVAL);
		}
		dt = (cur_time - prev_time);
		delay -= dt;
	}
}

static
void	stt_update_sim(bool eat, t_philo *philo)
{
	stt_update_clock(0, philo);
	if (eat == 1)
	{
		*philo->state = e_eat;
		philo->params.eat_count--;
		stt_update_clock(philo->params.eat, philo);
		pthread_mutex_unlock(philo->forks[0]);
		pthread_mutex_unlock(philo->forks[1]);
		*philo->state = e_sleep;
		stt_update_clock(philo->params.sleep, philo);
		*philo->state = e_idle;
	}
}

static
void	stt_philo_main(t_philo philo)
{
	while (philo.params.eat_count > 0)
	{
		stt_update_sim(0, &philo);
		pthread_mutex_lock(philo.forks[philo.index & 1]);
		*philo.state = e_fork0;
		stt_update_sim(0, &philo);
		pthread_mutex_lock(philo.forks[!(philo.index & 1)]);
		*philo.state = e_fork1;
		stt_update_sim(1, &philo);
	}
	*philo.state = e_done;
}

void	*philo_start(void *varg)
{
	const t_philo	philo = *(t_philo *)varg;

	*philo.state = e_idle;
	while (*philo.time_now == 0)
		usleep(FT_UPDATE_INTERVAL);
	if (philo.forks[0] == philo.forks[1])
	{
		pthread_mutex_lock(philo.forks[0]);
		*philo.state = e_fork0;
		return (NULL);
	}
	stt_philo_main(philo);
	return (NULL);
}
