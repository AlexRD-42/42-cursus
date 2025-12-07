/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:53:11 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/27 19:08:33 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include <sys/time.h>
#include <stdatomic.h>
#include <threads.h>
#include <pthread.h>
#include <stdio.h>

/* Compensation
	Assuming the outcome of grabbing forks (mutex locking) is random, we can
	introduce a rule where philos that are fine relinquish the fork, while those
	near death hold on to it. This can introduce a deadlock, but considering
	that death should be avoided at all costs, it's not a problem.
*/

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]

int	test(long delay)
{
	size_t			i;
	struct timeval	var;
	__suseconds_t	test[16384];
	__suseconds_t	test2[16384];
	long 			max = LONG_MIN, min = LONG_MAX;
	double			avg = 0;
	size_t			count = 0;

	i = 0;
	while (i < 16384)
	{
		usleep(delay);
		gettimeofday(&var, NULL);
		test[i] = var.tv_usec;
		i++;
	}
	i = 1;
	while (i < 16384)
	{
		test2[i] = test[i] - test[i - 1];
		i++;
	}
	i = 1;
	while (i < 16384)
	{
		if (test2[i] >= 0)
		{
			if (test2[i] > max)
				max = test2[i];
			if (test2[i] < min)
				min = test2[i];
			avg += test2[i];
			count++;
		}
		i++;
	}
	avg = avg / (double) count;
	printf("DELAY: %ld, MIN: %ld, MAX: %ld, AVG: %f\n", delay, min, max, avg);
	return (0);
}

int main(void)
{
	atomic_long	i;
	i = 1;
	while (i <= 256)
	{
		test(i);
		i *= 2;
	}
}
