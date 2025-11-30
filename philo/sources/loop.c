/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:18:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/30 18:20:12 by adeimlin         ###   ########.fr       */
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

// timestamp_in_ms X has taken a fork
// timestamp_in_ms X is eating
// timestamp_in_ms X is sleeping
// timestamp_in_ms X is thinking
// timestamp_in_ms X died

static inline
long	stt_update_clock(bool eat, long delay, t_philo *philo)
{
	static thread_local long	cur_time = 0;
	static thread_local long	last_meal = 0;
	long						dt;
	long						prev_time;

	if (eat == 1)
		last_meal = cur_time;
	while (delay >= 0)
	{
		prev_time = cur_time;
		while (cur_time == prev_time)
		{
			cur_time = *philo->time_now;
			usleep(FT_UPDATE_INTERVAL);
		}
		dt = (cur_time - prev_time);
		if (cur_time - last_meal >= philo->time.death)
			return (1);	// DED
		delay -= dt;
	}
	return (0);
}

static
int	stt_update_sim(bool eat, t_philo *philo)
{
	if (stt_update_clock(0, 10, philo))
		return (1);
	if (eat == 1)
	{
		*philo->state = e_eat;
		philo->eat_count--;
		if (stt_update_clock(1, philo->time.eat, philo))
			return (1);
		pthread_mutex_unlock(philo->forks[0]);
		pthread_mutex_unlock(philo->forks[1]);
		*philo->state = e_sleep;
		if (stt_update_clock(0, philo->time.sleep, philo))
			return (1);
		*philo->state = e_idle;
	}
	return (0);
}

// Returns: 0) Alive, 1) Dead
static
int	stt_philo_main(t_philo philo)
{
	while (true)
	{
		if (philo.eat_count == 0)
			return (0);
		if (stt_update_sim(0, &philo))
			break ;
		pthread_mutex_lock(philo.forks[philo.index & 1]);
		*philo.state = e_fork;
		if (stt_update_sim(0, &philo))
			break ;
		pthread_mutex_lock(philo.forks[!(philo.index & 1)]);
		*philo.state = e_fork;
		if (stt_update_sim(1, &philo))
			break ;
	}
	*philo.state = e_death;
	return (1);
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
		*philo.state = e_fork;
		while (stt_update_clock(0, 0, &philo) == 0)
			;
		*philo.state = e_death;
		return (NULL);
	}
	stt_philo_main(philo);
	return (NULL);
}
