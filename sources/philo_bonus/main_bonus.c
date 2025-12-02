/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 13:46:45 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include "philosophers_bonus.h"

static
int	stt_let_there_be_life(t_params params, pid_t *cpid_list, const char *sem_name)
{
	size_t	i;
	pid_t	process_id;

	i = 0;
	while (i < params.count)
	{
		process_id = fork();
		if (process_id == 0)
			return (philo_start(i, params, sem_name));
		else if (process_id > 0)
			cpid_list[i] = process_id;
		else
			return (-1);
		i++;
	}
	return (0);
}

int			argc = 2;
const char	*argv[2] = {NULL, "5 401 200 100"};

// num_ph, die, eat, sleep, eat_count
int	main(void)
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
	while (1)
		;
	sem_close(sem);
	sem_unlink(sem_name);
	return (rvalue);
}
