/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:18:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/28 18:41:04 by adeimlin         ###   ########.fr       */
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
int	stt_update_clock(bool eat, long delay, long death_time, const atomic_long *real_time)
{
	static thread_local long	cur_time = 0;
	static thread_local long	death_timer = 0;
	long						dt;
	long						prev_time;
	const long					interval = FT_UPDATE_INTERVAL + delay / 4;	// 2x nyquist freq

	if (eat == 1)
		death_timer = 0;
	while (delay >= 0)
	{
		prev_time = cur_time;
		while (cur_time == prev_time)
		{
			cur_time = *real_time;
			usleep(interval);
		}
		dt = (cur_time - prev_time);
		death_timer += dt;
		if (death_timer > death_time)
			return (1);	// DED
		delay -= dt;
	}
	return (0);
}

static
int	stt_update_sim(bool eat, const t_philo *philo)
{
	if (eat == 1)
	{
		write(STDOUT_FILENO, "A philosopher is eating\n", 24);
		if (stt_update_clock(eat, philo->time.eat, philo->time.death, philo->time.real))
			return (1);
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		write(STDOUT_FILENO, "A philosopher is sleeping\n", 26);
		if (stt_update_clock(eat, philo->time.sleep, philo->time.death, philo->time.real))
			return (1);
		write(STDOUT_FILENO, "A philosopher is thinking\n", 26);
	}
	else
	{
		if (stt_update_clock(eat, 0, philo->time.death, philo->time.real))
			return (1);
	}
	return (0);
}

static
void	stt_philo_main(const t_philo philo, volatile atomic_size_t *death_id)
{
	while (true)
	{
		pthread_mutex_lock(philo.forks[philo.index & 1]);
		if (stt_update_sim(0, &philo))
			break ;
		pthread_mutex_lock(philo.forks[!(philo.index & 1)]);
		if (stt_update_sim(1, &philo))
			break ;
		if (stt_update_sim(0, &philo))
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
		{{arg->cfg->mutex, arg->cfg->mutex + arg->index % arg->cfg->count}}};

	while (*philo.time.real != 0)
		usleep(FT_UPDATE_INTERVAL);
	stt_philo_main(philo, &(arg->cfg->death_id));
}
