/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:18:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/30 13:55:36 by adeimlin         ###   ########.fr       */
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

static
int	stt_print_state(uint8_t state, const char *index_str, const atomic_long *time_now, const atomic_size_t *death_id)
{
	static const char	*msg[5] = {" died", " is eating", " is thinking", " is sleeping", " has taken a fork"};
	char				buffer[32];
	const char			*ptr = ft_itoa_stack(*time_now / 1000, buffer + 31);

	if (*death_id == SIZE_MAX || (*death_id != SIZE_MAX && state == 0))
		ft_writev(STDOUT_FILENO, (const char *[5]){ptr, "ms: ", index_str, msg[state], NULL}, '\n');
	return (0);
}

static inline
long	stt_update_clock(bool eat, long delay, long death_time, const atomic_long *time_now)
{
	static thread_local long	cur_time = 0;
	static thread_local long	death_timer = 0;
	long						dt;
	long						prev_time;
	long						elapsed_time;

	if (eat == 1)
		death_timer = 0;
	elapsed_time = 0;
	while (elapsed_time <= delay)
	{
		prev_time = cur_time;
		while (cur_time == prev_time)
		{
			cur_time = *time_now;
			usleep(FT_UPDATE_INTERVAL);
		}
		dt = (cur_time - prev_time);
		death_timer += dt;
		if (death_timer >= death_time)
			return (1);	// DED
		elapsed_time += dt;
	}
	return (0);
}

static
int	stt_update_sim(bool eat, t_philo *philo, const char *index_str)
{
	if (stt_update_clock(0, 10, philo->time.death, philo->time_now))
		return (1);
	if (eat == 1)
	{
		stt_print_state(1, index_str, philo->time_now, philo->death_id);
		philo->eat_count--;
		if (stt_update_clock(1, philo->time.eat, philo->time.death, philo->time_now))
			return (1);
		pthread_mutex_unlock(philo->forks[0]);
		pthread_mutex_unlock(philo->forks[0]);
		stt_print_state(3, index_str, philo->time_now, philo->death_id);
		if (stt_update_clock(0, philo->time.sleep, philo->time.death, philo->time_now))
			return (1);
		stt_print_state(2, index_str, philo->time_now, philo->death_id);
	}
	return (0);
}

// Returns: 0) Alive, 1) Dead
static
int	stt_philo_main(t_philo philo, const char *index_str)
{
	while (true)
	{
		if (philo.eat_count == 0)
			return (0);
		if (stt_update_sim(0, &philo, index_str))
			break ;
		pthread_mutex_lock(philo.forks[philo.index & 1]);
		stt_print_state(4, index_str, philo.time_now, philo.death_id);
		if (stt_update_sim(0, &philo, index_str))
			break ;
		pthread_mutex_lock(philo.forks[!(philo.index & 1)]);
		stt_print_state(4, index_str, philo.time_now, philo.death_id);
		if (stt_update_sim(1, &philo, index_str))
			break ;
	}
	*philo.death_id = philo.index;
	stt_print_state(0, index_str, philo.time_now, philo.death_id);
	return (1);
}

void	*philo_start(void *varg)
{
	char				index_str[32];
	const t_philo		philo = *(t_philo *)varg;
	const char			*ptr = ft_itoa_stack((int64_t)philo.index, index_str + 31);

	*philo.death_id = 1;
	while (*philo.time_now == 0)
		usleep(FT_UPDATE_INTERVAL);
	if (philo.forks[0] == philo.forks[1])
	{
		pthread_mutex_lock(philo.forks[0]);
		stt_print_state(4, ptr, philo.time_now, philo.death_id);
		while (stt_update_clock(0, 0, philo.time.death, philo.time_now) == 0)
			;
		*philo.death_id = philo.index;
		stt_print_state(0, ptr, philo.time_now, philo.death_id);
		return (NULL);
	}
	stt_philo_main(philo, ptr);
	return (NULL);
}
