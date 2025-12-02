/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:36:15 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 15:58:50 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_common.h"
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <unistd.h>
#include <semaphore.h>
#include <threads.h>
#include <philosophers_bonus.h>

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
		sem_wait(philo.sem);
		if (stt_change_state(e_fork0, philo.state, philo.time_now, 0))
			return (1);
		sem_wait(philo.sem);
		if (stt_change_state(e_fork1, philo.state, philo.time_now, 0))
			return (1);
		if (stt_change_state(e_eat, philo.state, philo.time_now, philo.params.eat))
			return (1);
		philo.params.eat_count--;
		sem_post(philo.sem);
		sem_post(philo.sem);
		if (stt_change_state(e_sleep, philo.state, philo.time_now, philo.params.sleep))
			return (1);
		if (stt_change_state(e_idle, philo.state, philo.time_now, 0))
			return (1);
	}
	stt_change_state(e_done, philo.state, philo.time_now, 0);
	return (0);
}

int	philo_start(size_t index, t_params params, const char *sem_name)
{
	int				rvalue;
	t_philo			philo;
	t_thread_cfg	cfg;
	pthread_t		thread_id;

	cfg.index = index;
	cfg.params = params;
	cfg.time_now = 0;
	cfg.state = e_idle;
	cfg.sem = sem_open(sem_name, 0);
	if (cfg.sem == SEM_FAILED)
		return(1);
	pthread_create(&thread_id, NULL, monitor_start, (void *) &cfg);
	pthread_detach(thread_id);
	philo = (t_philo){cfg.index, cfg.params, &cfg.time_now, &cfg.state, cfg.sem};
	while (cfg.time_now == 0)
		usleep(FT_UPDATE_INTERVAL);
	rvalue = stt_philo_main(philo);
	while (true)
		;
	return(rvalue);
}
