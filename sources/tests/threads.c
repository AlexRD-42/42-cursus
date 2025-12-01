/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:33:45 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/27 13:34:35 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include "philosophers.h"

typedef struct s_test
{
	size_t			index;
	int64_t			value;
	pthread_mutex_t	mutex;
}	t_test;

// static
// void	*stt_worker(void *varg)
// {
// 	t_test			*arg = (t_test *)varg;
// 	char			buffer[32];
// 	const char		*ptr = ft_itoa_stack(arg->value, buffer + 31);

// 	pthread_mutex_lock(&arg->mutex);
// 	arg->value++;
// 	buffer[31] = '\n';
// 	write(1, "I am thread number: ", 20);
// 	write(1, ptr, (size_t)(buffer - ptr) + 32);
// 	pthread_mutex_unlock(&arg->mutex);
// 	return (NULL);
// }

// int	main(void)
// {
// 	pthread_t	threads[FT_MAX_PHILO];
// 	t_test		test;

// 	test.value = 0;
// 	test.index = 0;
// 	pthread_mutex_init(&test.mutex, NULL);
// 	while (test.index < 64)
// 	{
// 		pthread_create(threads + test.index, NULL, stt_worker, &test);
// 		test.index++;
// 	}
// }

static
void	*stt_worker(void *varg)
{
	int64_t			arg = (int64_t) varg;
	char			buffer[32];
	const char		*ptr = ft_itoa_stack(arg, buffer + 31);

	buffer[31] = '\n';
	write(1, "I am thread number: ", 20);
	write(1, ptr, (size_t)(buffer - ptr) + 32);
	return (NULL);
}

int	main(void)
{
	size_t		i;
	pthread_t	threads[FT_MAX_PHILO];

	i = 0;
	while (i < 64)
	{
		pthread_create(threads + i, NULL, stt_worker, (void *) i);
		i++;
	}
}
