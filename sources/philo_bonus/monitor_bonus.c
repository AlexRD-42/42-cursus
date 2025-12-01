/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:18:29 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/01 11:31:16 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdatomic.h>
#include <sys/time.h>
#include "philosophers.h"

static inline
int	stt_print_state(uint8_t state, size_t index, const char *time_str)
{
	char				buffer[32];
	const char			*ptr = ft_itoa_r((int64_t)index, buffer + 31);
	static const char	*msg[6] = {" died", " is thinking", " has taken a fork", " has taken a fork", " is eating",
		" is sleeping"};

	ft_writev(STDOUT_FILENO, (const char *[5]){time_str, "ms: ", ptr, msg[state], NULL}, '\n');
	return (state);
}

static
int	stt_monitor_state(atomic_long *time_now, atomic_char *state, t_time time)
{
	struct timeval	now;
	long			start;
	long			last_meal;
	long			local_time_now;

	last_meal = 0;
	gettimeofday(&now, NULL);
	start = now.tv_sec * 1000000 + now.tv_usec;
	while (true)
	{
		usleep(FT_UPDATE_INTERVAL);
		gettimeofday(&now, NULL);
		local_time_now = (1000000 * now.tv_sec + now.tv_usec) - start;
		*time_now = local_time_now;
		if (local_time_now - last_meal > time.death)
			_exit(stt_print_state(*state, ));
		if (cur_state != cfg->prev_state[i])
		{
			if (cur_state == e_eat)
				last_meal[i] = cfg->time_now;
			cfg->prev_state[i] = stt_print_state((uint8_t)cur_state, i, time_str);
		}
	}
}

void	*monitor_start(void *arg)
{
	atomic_long	*time_now;
	atomic_char	*state;
	
	
}