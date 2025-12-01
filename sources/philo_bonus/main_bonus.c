/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/01 17:36:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/types/struct_timeval.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdatomic.h>
#include <sys/time.h>
#include <pthread.h>
#include "philosophers_bonus.h"

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
int	stt_monitor_state(t_thread_cfg *cfg, const t_params params)
{
	struct timeval	now;
	long			start;
	long			last_meal;
	long 			local_time_now;

	last_meal = 0;
	gettimeofday(&now, NULL);
	start = now.tv_sec * 1000000 + now.tv_usec;
	while (true)
	{
		usleep(FT_UPDATE_INTERVAL);
		gettimeofday(&now, NULL);
		local_time_now = (1000000 * now.tv_sec + now.tv_usec) - start;
		cfg->time_now = local_time_now;
		if (local_time_now - last_meal > params.death)
			_exit(stt_print_state(cfg->state, cfg->index, ));
		if (cur_state != cfg->prev_state[i])
		{
			if (cur_state == e_eat)
				last_meal[i] = cfg->time_now;
			cfg->prev_state[i] = stt_print_state((uint8_t)cur_state, i, time_str);
		}
	}
}

void	*monitor_start(void *varg)
{
	const t_philo	philo = *(t_philo *) varg;
	
}

// num_ph, die, eat, sleep, eat_count
int	main(void)
{
	static t_sim_cfg	cfg = {.time_now = 0};
	long				start;
	struct timeval		now;

	int			argc = 2;
	const char	*argv[2] = {NULL, "5 401 200 100"};


	return (0);
}
