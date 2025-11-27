/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/27 16:11:45 by adeimlin         ###   ########.fr       */
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

/* Compensation
	Assuming the outcome of grabbing forks (mutex locking) is random, we can
	introduce a rule where philos that are fine relinquish the fork, while those
	near death hold on to it. This can introduce a deadlock, but considering
	that death should be avoided at all costs, it's not a problem.
*/

int	main(int argc, const char **argv)
{
	size_t			i;
	atomic_long		time;
	atomic_long		start;
	t_philo_cfg		*cfg;
	struct timeval	timer;

	time = 0;
	cfg = philo_init(argc, argv);
	if (cfg == NULL)
		return (1);
	usleep(5000);
	gettimeofday(&timer, NULL);
	start = timer.tv_usec;
	time = 1;
	while (true)
	{
		time = timer.tv_usec - start;
		gettimeofday(&timer, NULL);
		usleep(8);
		i = 0;
		// while (i < cfg->count)
		
	}
	return (0);
}
