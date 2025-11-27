/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/27 12:25:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bits/types.h>
#include <bits/types/struct_timeval.h>
#include <stdint.h>
#include <stddef.h>
#include <sys/select.h>
#include <sys/time.h>
#include <threads.h>
#include <unistd.h>
#include <pthread.h>
#include "philosophers.h"

/* Compensation
	Assuming the outcome of grabbing forks (mutex locking) is random, we can
	introduce a rule where philos that are fine relinquish the fork, while those
	near death hold on to it. This can introduce a deadlock, but considering
	that death should be avoided at all costs, it's not a problem.
*/

long	usec_interval(void)
{
	static thread_local struct timeval	time;
	long								usec;

	usec = time.tv_usec;
	gettimeofday(&time, NULL);
	return (time.tv_usec - usec);
}

long	get_usec(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_usec);
}

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
int	main(int argc, const char **argv)
{
	struct timeval	var;
	struct timeval	var2;

	gettimeofday(&var, NULL);
	usleep(1);
	gettimeofday(&var2, NULL);
}
