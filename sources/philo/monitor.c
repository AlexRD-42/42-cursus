/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:01:35 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/04 09:31:51 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <sys/time.h>
#include "philosophers.h"

// num_ph, die, eat, sleep, eat_count
static inline
int	stt_print_state(uint8_t state, size_t index, long time_now)
{
	char				buffer[64];
	const char			*time_str = ft_itoa_r(time_now / 1000, buffer + 31);
	const char			*index_str = ft_itoa_r((int64_t)index + 1, buffer + 63);
	static const char	*msg[7] = {" died", " is thinking", " has taken a fork",
		" has taken a fork", " is eating", " is sleeping", ""};

	ft_writev(STDOUT_FILENO, (const char *[5])
		{time_str, "ms: ", index_str, msg[state], NULL}, '\n');
	return (state);
}

// Returns 1 on death or done
static inline
int	stt_get_state(t_sim_cfg *cfg, long time_now)
{
	size_t		i;
	size_t		done_count;
	static long	last_meal[FT_MAX_PHILO] = {0};
	uint8_t		cur_state;

	i = 0;
	done_count = 0;
	while (i < cfg->params.count)
	{
		cur_state = cfg->state[i];
		done_count += cur_state == e_done;
		if (cur_state != e_done && time_now - last_meal[i] > cfg->params.death)
			return (stt_print_state(0, i, time_now) == 0);	// DED
		if (cur_state != e_done && cur_state != cfg->prev_state[i])
		{
			if (cur_state == e_eat)
				last_meal[i] = time_now;
			cfg->prev_state[i] = stt_print_state(cur_state, i, time_now);
		}
		i++;
	}
	return (done_count == cfg->params.count);
}

int	monitor_state(t_sim_cfg *cfg)
{
	long			start;
	struct timeval	now;

	gettimeofday(&now, NULL);
	start = now.tv_sec * 1000000 + now.tv_usec;
	while (stt_get_state(cfg, cfg->time_now) == 0)
	{
		usleep(FT_UPDATE_INTERVAL);
		gettimeofday(&now, NULL);
		cfg->time_now = (1000000 * now.tv_sec + now.tv_usec) - start;
	}
	return (0);
}
