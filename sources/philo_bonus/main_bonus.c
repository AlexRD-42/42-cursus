/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/04 10:33:36 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include "philosophers_bonus.h"
#include <sys/wait.h>

static
void	stt_terminate(pid_t *cpid_list, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		kill(cpid_list[i], SIGKILL);
		i++;
	}
	i = 0;
	while (i < count)
	{
		waitpid(cpid_list[i], NULL, 0);
		i++;
	}
}

static int	\
stt_let_there_be_life(t_params params, pid_t *cpid_list, const char *sem_name)
{
	size_t	count;
	int		status;
	pid_t	process_id;

	count = 0;
	while (count < params.count)
	{
		process_id = fork();
		if (process_id == 0)
			exit(philo_start(count, params, sem_name));
		else if (process_id > 0)
			cpid_list[count] = process_id;
		else
		{
			stt_terminate(cpid_list, count);
			return (1);
		}
		count++;
	}
	waitpid(-1, &status, 0);
	stt_terminate(cpid_list, count);
	return (0);
}

// num_ph, die, eat, sleep, eat_count
int	main(int argc, const char **argv)
{
	int			rvalue;
	t_params	params;
	sem_t		*sem;
	const char	sem_name[8] = "__forks";
	pid_t		cpid_list[FT_MAX_PHILO];

	sem_unlink(sem_name);
	rvalue = 0;
	if (init_params(argc, argv, &params) != 0)
		return (1);
	sem = sem_open(sem_name, O_CREAT | O_EXCL, 0644, params.count);
	if (sem == SEM_FAILED)
		return (1);
	if (stt_let_there_be_life(params, cpid_list, sem_name))
		rvalue = 1;
	sem_close(sem);
	sem_unlink(sem_name);
	return (rvalue);
}
