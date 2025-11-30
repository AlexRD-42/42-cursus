/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/30 18:57:01 by adeimlin         ###   ########.fr       */
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
void	stt_print_state(uint8_t state, size_t index, const char *time_str)
{
	char				buffer[32];
	const char			*ptr = ft_itoa_r((int64_t)index, buffer + 31);
	static const char	*msg[6] = {" died", " is thinking", " has taken a fork", " has taken a fork", " is eating",
		" is sleeping"};

	ft_writev(STDOUT_FILENO, (const char *[5]){time_str, "ms: ", ptr, msg[state], NULL}, '\n');
}

static
int	stt_get_state(t_shared_cfg *cfg)
{
	size_t		i;
	static long	last_meal[FT_MAX_PHILO] = {0};
	const char	*time_str = ft_itoa_stt(cfg->time_now / 1000);
	char		cur_state;

	i = 0;
	while (i < cfg->count)
	{
		cur_state = cfg->state[i];
		if (cur_state == e_done)
			continue ;
		if (cfg->time_now - last_meal[i] > cfg->time.death)
		{
			stt_print_state(0, i, time_str);	// DED
			return (1);
		}
		if (cur_state != cfg->prev_state[i])
		{
			if (cur_state == e_eat)
				last_meal[i] = cfg->time_now;
			cfg->prev_state[i] = cur_state;
			stt_print_state((uint8_t)cur_state, i, time_str);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	static t_shared_cfg	cfg = {.time_now = 0};
	long				start;
	struct timeval		now;

	int			argc = 2;
	const char	*argv[2] = {NULL, "2 401 200 100 5"};

	if (sim_init(argc, argv, &cfg))
		return (1);
	gettimeofday(&now, NULL);
	start = now.tv_sec * 1000000 + now.tv_usec;
	while (true)	// condition where each philo eats min
	{
		usleep(FT_UPDATE_INTERVAL);
		gettimeofday(&now, NULL);
		cfg.time_now = (1000000 * now.tv_sec + now.tv_usec) - start;
		if (stt_get_state(&cfg))
			break ;
	}
	return (0);
}
