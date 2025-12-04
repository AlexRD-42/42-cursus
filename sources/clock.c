/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:35:23 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/04 09:42:30 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdatomic.h>
#include <threads.h>
#include "philosophers_common.h"

static inline long	\
stt_update_time(long prev_time, long cur_time, const atomic_long *time_now)
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

int	change_state\
(uint8_t new_state, atomic_uchar *state, const atomic_long *tnow, long delay)
{
	if (stt_update_clock(0, tnow))
		return (1);
	*state = new_state;
	if (stt_update_clock(delay, tnow))
		return (1);
	return (0);
}
