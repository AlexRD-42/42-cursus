/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:15:10 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/05 11:45:55 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <stdint.h>
# include <stddef.h>
# include <stdatomic.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include "philosophers_common.h"


// PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP
// PTHREAD_MUTEX_ERRORCHECK_NP
int	main(int argc, char **argv, char **envp)
{
	pthread_mutex_t		stt_mutex = {{0, 0, 0, 0, PTHREAD_MUTEX_ERRORCHECK_NP, 0, 0, {((void *)0), ((void *)0) }}};
	pthread_mutex_t		stt2_mutex;
	pthread_mutex_t		reg_mutex;
	pthread_mutex_t		reg2_mutex;
	pthread_mutexattr_t	attr;

	memset(&stt2_mutex, 0, sizeof(pthread_mutex_t));
	stt2_mutex.__data.__kind = 2;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
	pthread_mutex_init(&reg_mutex, &attr);
	pthread_mutex_init(&reg2_mutex, &attr);

}
