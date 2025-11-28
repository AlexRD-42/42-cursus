/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/28 12:36:07 by adeimlin         ###   ########.fr       */
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

static
int	stt_start()
{
	atomic_long				time;
	long					start;
	volatile atomic_size_t	philo_death;	// Flag for philo death
	struct timeval			timer;

	time = 0;
	philo_death = 0;
	usleep(5000);
	gettimeofday(&timer, NULL);
	start = timer.tv_usec;
	time = 1;
	while (philo_death == 0 && count < total)	// condition where each philo eats min
	{
		time = timer.tv_usec - start;
		gettimeofday(&timer, NULL);
		usleep(8);
	}
	return (0);
}

// Could do interpolation per update!
// Each worker has its own internal tick, where then the average speed of 
// each tick is calculated by the linear interp of each update. Really unnecessary though
int	main(int argc, const char **argv)
{
	size_t				i;
	static t_philo_shared	philo_cfg;
	static t_sim_cfg	sim_cfg;

	if (sim_init(argc, argv))
		return (1);

}


