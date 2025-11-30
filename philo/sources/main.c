/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/29 17:45:47 by adeimlin         ###   ########.fr       */
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
int	main(void)
{
	static t_shared_cfg	cfg = {.time_now = 0};
	long				start;
	struct timeval		now;

	int			argc = 2;
	const char	*argv[2] = {NULL, "4 301 200 100"};

	if (sim_init(argc, argv, &cfg))
		return (1);
	gettimeofday(&now, NULL);
	start = now.tv_sec * 1000000 + now.tv_usec;
	while (cfg.death_id == SIZE_MAX)	// condition where each philo eats min
	{
		usleep(FT_UPDATE_INTERVAL);
		gettimeofday(&now, NULL);
		cfg.time_now = (1000000 * now.tv_sec + now.tv_usec) - start;
	}
	return (0);
}
