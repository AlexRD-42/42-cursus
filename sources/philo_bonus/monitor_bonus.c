/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:59:51 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/05 15:01:48 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include "philosophers_common.h"
#include "philosophers_bonus.h"

static inline
int	stt_print_state(uint8_t state, long local_time_now, const char *istr)
{
	char				buffer[32];
	const char			*tstr = ft_itoa_r(local_time_now / 1000, buffer + 31);
	static const char	*msg[7] = {" died", " is thinking", " has taken a fork",
		" has taken a fork", " is eating", " is sleeping", NULL};
	const char			*msg_vec[5] = {tstr, " ", istr, msg[state], NULL};

	ft_writev(STDOUT_FILENO, msg_vec, '\n');
	return (state);
}

static inline
int	stt_update(t_thread_cfg *cfg, long start, const char *index_str)
{
	struct timeval	now;
	static uint8_t	prev_state = e_idle;
	long			local_time_now;
	long			local_cur_state;		// Local vars so that only one atomic access is used

	gettimeofday(&now, NULL);
	local_time_now = (1000000 * now.tv_sec + now.tv_usec) - start;
	local_cur_state = cfg->state;		// Only one access
	cfg->time_now = local_time_now;		// Only one access
	if (local_cur_state != prev_state)
	{
		if (local_cur_state == e_eat)
			cfg->last_meal = cfg->time_now;
		prev_state = stt_print_state(local_cur_state, local_time_now, index_str);
	}
	if (local_time_now - cfg->last_meal > cfg->params.death)
		local_cur_state = e_death;
	return (local_cur_state);
}

static
int	stt_monitor_state(t_thread_cfg *cfg, const char *index_str)
{
	uint8_t			state;
	struct timeval	now;
	long			start;

	gettimeofday(&now, NULL);
	start = now.tv_sec * 1000000 + now.tv_usec;
	state = e_idle;
	while (state != e_death && state != e_done)
	{
		usleep(FT_UPDATE_INTERVAL);
		state = stt_update(cfg, start, index_str);
	}
	cfg->time_now = -1;
	exit(state == e_death);
}

void	*monitor_start(void *varg)
{
	t_thread_cfg	*cfg;
	char			buffer[32];
	const char		*index_str;

	cfg = (t_thread_cfg *)varg;
	index_str = ft_itoa_r((int64_t)(cfg->index + 1), buffer + 31);
	stt_monitor_state(cfg, index_str);
	return (NULL);
}
