/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/01 14:28:36 by adeimlin         ###   ########.fr       */
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
#include "philosophers.h"

// num_ph, die, eat, sleep, eat_count
// Could do interpolation per update!
// Each worker has its own internal tick, where then the average speed of 
// each tick is calculated by the linear interp of each update. Really unnecessary though

static inline
int	stt_print_state(uint8_t state, size_t index, const char *time_str)
{
	char				buffer[32];
	const char			*ptr = ft_itoa_r((int64_t)index + 1, buffer + 31);
	static const char	*msg[6] = {" died", " is thinking", " has taken a fork", " has taken a fork", " is eating",
		" is sleeping"};

	ft_writev(STDOUT_FILENO, (const char *[5]){time_str, "ms: ", ptr, msg[state], NULL}, '\n');
	return (state);
}

static
int	stt_get_state(t_sim_cfg *cfg)
{
	size_t		i;
	size_t		done_count;
	static long	last_meal[FT_MAX_PHILO] = {0};
	const char	*time_str = ft_itoa_stt(cfg->time_now / 1000);
	char		cur_state;

	i = 0;
	done_count = 0;
	while (i < cfg->params.count)
	{
		cur_state = cfg->state[i];
		done_count += cur_state == e_done;
		if (cur_state != e_done && cfg->time_now - last_meal[i] > cfg->params.death)
			return (stt_print_state(0, i, time_str) == 0);	// DED
		if (cur_state != cfg->prev_state[i])
		{
			if (cur_state == e_eat)
				last_meal[i] = cfg->time_now;
			cfg->prev_state[i] = stt_print_state((uint8_t)cur_state, i, time_str);
		}
		i++;
	}
	return (done_count == cfg->params.count);
}

int	main(void)
{
	static t_sim_cfg	cfg = {.time_now = 0};
	long				start;
	struct timeval		now;

	int			argc = 2;
	const char	*argv[2] = {NULL, "5 401 200 100"};

	if (sim_init(argc, argv, &cfg))
		return (1);
	gettimeofday(&now, NULL);
	start = now.tv_sec * 1000000 + now.tv_usec;
	while (true)
	{
		usleep(FT_UPDATE_INTERVAL);
		gettimeofday(&now, NULL);
		cfg.time_now = (1000000 * now.tv_sec + now.tv_usec) - start;
		if (stt_get_state(&cfg))
			break ;
	}
	return (0);
}
