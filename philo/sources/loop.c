/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:18:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/29 15:59:16 by adeimlin         ###   ########.fr       */
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

// state = 0 update clock
static
int	stt_print_state(uint8_t state, const char *index_str)
{
	static const char	*msg[5] = {" died", " is eating", " is thinking", " is sleeping", " has taken a fork"};
	const char			*array[3] = {index_str, msg[state], NULL};

	ft_writev(STDOUT_FILENO, array, '\n');
	return (0);
}

static inline
long	stt_update_clock(bool eat, long delay, long death_time, const volatile atomic_long *real_time)
{
	static thread_local long	cur_time = 0;
	static thread_local long	death_timer = 0;
	long						dt;
	long						prev_time;

	if (eat == 1)
		death_timer = 0;
	while (delay >= 0)
	{
		prev_time = cur_time;
		while (cur_time == prev_time)
		{
			cur_time = *real_time;
			usleep(FT_UPDATE_INTERVAL + delay / 4);	// Gets more precise the closer it is
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
int	stt_update_sim(bool eat, t_philo *philo, const char *index_str)
{
	stt_update_clock(0, 0, philo->time.death, philo->time_now);
	if (eat == 1)
	{
		stt_print_state(1, index_str);
		philo->eat_count--;
		if (stt_update_clock(eat, philo->time.eat, philo->time.death, philo->time_now))
			return (1);
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		stt_print_state(3, index_str);
		if (stt_update_clock(0, philo->time.sleep, philo->time.death, philo->time_now))
			return (1);
		stt_print_state(2, index_str);
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
		stt_print_state(4, index_str);
		pthread_mutex_lock(philo.forks[philo.index & 1]);
		if (stt_update_sim(0, &philo, index_str))
			break ;
		stt_print_state(4, index_str);
		pthread_mutex_lock(philo.forks[!(philo.index & 1)]);
		if (stt_update_sim(1, &philo, index_str))
			break ;
		if (stt_update_sim(0, &philo, index_str))
			break ;
	}
	*philo.death_id = philo.index;
	stt_print_state(0, index_str);
	return (1);
}

// Preps the needs structs, preps the messages
// Then waits until the timer starts
void	*philo_start(void *varg)
{
	char				index_str[32];
	const t_philo		philo = *(t_philo *)varg;
	const char			*ptr = ft_itoa_stack((int64_t)philo.index, index_str + 31);

	*philo.death_id = 1;
	while (*philo.time_now == 0)
		usleep(FT_UPDATE_INTERVAL);
	stt_philo_main(philo, ptr);
	return (NULL);
}
