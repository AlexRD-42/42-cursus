/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 09:35:23 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/05 10:00:20 by adeimlin         ###   ########.fr       */
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
	cur_time = *time_now;
	while (cur_time == prev_time)
	{
		usleep(FT_UPDATE_INTERVAL);
		cur_time = *time_now;
	}
	return (cur_time);
}

int	update_clock(long delay, const atomic_long *time_now)
{
	static thread_local long	cur_time = 0;
	long						dt;
	long						prev_time;

	prev_time = cur_time;
	cur_time = stt_update_time(prev_time, cur_time, time_now);
	dt = (cur_time - prev_time);
	delay -= dt;
	while (delay >= 0 && cur_time >= 0)
	{
		prev_time = cur_time;
		cur_time = stt_update_time(prev_time, cur_time, time_now);
		dt = (cur_time - prev_time);
		delay -= dt;
	}
	return (cur_time < 0);
}
