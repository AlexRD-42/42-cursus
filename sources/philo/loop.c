/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:18:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 15:00:10 by adeimlin         ###   ########.fr       */
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
long	stt_update_time(long prev_time, long cur_time, const atomic_long *time_now)
{
	while (cur_time == prev_time)
	{
		cur_time = *time_now;
		usleep(FT_UPDATE_INTERVAL);
	}
	return (cur_time);
}

static inline
int	stt_update_clock(long delay, const atomic_long *time_now)
{
	static thread_local long	cur_time = 0;
	static thread_local long	avg_delay = 0;
	long						dt;
	long						prev_time;

	prev_time = cur_time;
	cur_time = stt_update_time(prev_time, cur_time, time_now);
	dt = (cur_time - prev_time);
	avg_delay = avg_delay - avg_delay / 64 + dt / 64;
	delay -= dt;
	while (delay >= avg_delay / 2 && cur_time >= 0)
	{
		prev_time = cur_time;
		cur_time = stt_update_time(prev_time, cur_time, time_now);
		dt = (cur_time - prev_time);
		avg_delay = avg_delay - avg_delay / 64 + dt / 64;
		delay -= dt;
	}
	return (cur_time < 0);
}

static
int	stt_change_state(uint8_t new_state, atomic_uchar *state, const atomic_long *time_now, long delay)
{
	if (stt_update_clock(0, time_now))
		return (1);
	*state = new_state;
	if (stt_update_clock(delay, time_now))
		return (1);
	return (0);
}

static
int	stt_philo_main(t_philo philo)
{
	while (philo.params.eat_count > 0)
	{
		pthread_mutex_lock(philo.forks[philo.index & 1]);
		if (stt_change_state(e_fork0, philo.state, philo.time_now, 0))
			return (1);
		pthread_mutex_lock(philo.forks[!(philo.index & 1)]);
		if (stt_change_state(e_fork1, philo.state, philo.time_now, 0))
			return (1);
		if (stt_change_state(e_eat, philo.state, philo.time_now, philo.params.eat))
			return (1);
		philo.params.eat_count--;
		pthread_mutex_unlock(philo.forks[0]);
		pthread_mutex_unlock(philo.forks[1]);
		if (stt_change_state(e_sleep, philo.state, philo.time_now, philo.params.sleep))
			return (1);
		if (stt_change_state(e_idle, philo.state, philo.time_now, 0))
			return (1);
	}
	stt_change_state(e_done, philo.state, philo.time_now, 0);
	return (0);
}

void	*philo_start(void *varg)
{
	t_philo	philo;

	philo = *(t_philo *)varg;
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
