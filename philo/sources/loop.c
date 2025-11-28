/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:18:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/28 17:41:47 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <threads.h>
#include <unistd.h>
#include <string.h>
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
int	stt_update_sim(long delay, const t_time time, bool eat)
{
	static thread_local long	cur_time = 0;
	static thread_local long	death_timer = 0;
	long						dt;
	long						prev_time;
	const long					interval = FT_UPDATE_INTERVAL + delay / 4;	// 2x nyquist frequency

	if (eat == true)
		death_timer = 0;
	while (delay >= 0)
	{
		prev_time = cur_time;
		while (cur_time == prev_time)
		{
			cur_time = *time.real;
			usleep(interval);		// This should be proportional to delay!
		}
		dt = (cur_time - prev_time);
		death_timer += dt;
		if (death_timer > time.death)
			return (1);	// DED
		delay -= dt;
	}
	return (0);
}

// Attempts to eat. 
// Returns) 0) Alive 1) Dead
static
int	stt_philo_eat(const t_philo philo)
{
	if (philo.rfork == philo.lfork)
		return (0);
	if (philo.index % 2 == 0)
	{
		pthread_mutex_lock(philo.lfork);
		if (stt_update_sim(0, philo.time, 0))
			return (1);
		pthread_mutex_lock(philo.rfork);
	}
	else
	{
		pthread_mutex_lock(philo.rfork);
		if (stt_update_sim(0, philo.time, 0))
			return (1);
		pthread_mutex_lock(philo.lfork);
	}
	write(STDOUT_FILENO, "A philosopher is eating\n", 24);
	if (stt_update_sim(philo.time.eat, philo.time, 1))
			return (1);
	pthread_mutex_unlock(philo.rfork);
	pthread_mutex_unlock(philo.lfork);
	if (stt_update_sim(philo.time.sleep, philo.time, 0))
		return (1);
	return (0);
}

static
void	stt_philo_main(const t_philo philo, volatile atomic_size_t *death_id)
{
	while (true)
	{
		if (stt_philo_eat(philo) == 1)
			break ;
		if (stt_update_sim(0, philo.time, 0) == 1)
			break ;
	}
	*death_id = philo.index;
	write(STDOUT_FILENO, "A philosopher has died\n", 23);
}

// Preps the needs structs, preps the messages
// Then waits until the timer starts
void	*philo_start(void *varg)
{
	const t_philo_cfg	*arg = (t_philo_cfg *)varg;
	const t_philo		philo = {arg->index, arg->cfg->eat_count, arg->cfg->time,
		arg->cfg->mutex, arg->cfg->mutex + arg->index % arg->cfg->count};

	while (*philo.time.real != 0)
		usleep(FT_UPDATE_INTERVAL);
	stt_philo_main(philo, &(arg->cfg->death_id));
}
