/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:04:26 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/29 16:06:58 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <pthread.h>
#include "philosophers.h"

// Returns: 0) OK, -1) ARGCOUNT
static
int	stt_init_multiple(const char **argv, size_t count, t_shared_cfg *philos)
{
	size_t		i;
	const char	*str;
	int64_t		vars[5];

	i = 0;
	vars[4] = SIZE_MAX;
	while (i < count)
	{
		str = argv[i];
		while (*str == ' ' || (*str >= 9 && *str <= 14))
			str++;
		if (!(*str >= '0' && *str <= '9'))
			return (-1);
		vars[i] = ft_strtol(str);
		if (vars[i] < 0)
			return (-1);
		i++;
	}
	philos->count = (size_t) vars[0];
	philos->time.death = 1000 * (vars[1]);
	philos->time.eat = 1000 * (vars[2]);
	philos->time.sleep = 1000 * (vars[3]);
	philos->eat_count = (size_t) vars[4];
	return (0);
}

// num_ph, die, eat, sleep, eat_count
// Returns: 0) OK, -1) ARGCOUNT
static
int	stt_init_single(const char *str, t_shared_cfg *philos)
{
	size_t	i;
	int64_t	vars[5];

	i = 0;
	vars[4] = -1;
	while (i < 5 && *str >= '0' && *str <= '9')	// first char must be a number
	{
		vars[i] = ft_strtol(str);
		if (vars[i] < 0)
			return (-1);
		while (*str >= '0' && *str <= '9')
			str++;
		while (*str == ' ' || (*str >= 9 && *str <= 14))
			str++;
		i++;
	}
	if (*str != 0 || i < 4)
		return (-1);
	philos->count = (size_t) vars[0];
	philos->time.death = 1000 * vars[1];
	philos->time.eat = 1000 * vars[2];
	philos->time.sleep = 1000 * vars[3];
	philos->eat_count = (size_t) vars[4];
	return (0);
}

// Returns: 0) OK, -1) ARGCOUNT, -2) EINVAL, -4) Philos exceeded count
static
int	stt_input_validation(int argc, const char **argv, t_shared_cfg *philos)
{
	int	rvalue;

	if (argc != 2 && argc != 5 && argc != 6)
	{
		write(STDERR_FILENO, "init_error: invalid argument count\n", 35);
		return (-1);
	}
	if (argc == 2)
		rvalue = stt_init_single(argv[1], philos);
	else
		rvalue = stt_init_multiple(argv + 1, (size_t)(argc - 1), philos);
	if (rvalue == -1)
	{
		write(STDERR_FILENO, "init_error: argument is not a number\n", 37);
		return (-2);
	}
	if (philos->count > FT_MAX_PHILO)
	{
		write(STDERR_FILENO, "init_error: too many philos\n", 28);
		return (-4);
	}
	return (0);
}

static
int	stt_let_there_be_life(size_t index, t_shared_cfg *cfg)
{
	const pthread_mutex_t	*forks[2] = {cfg->mutex + index, cfg->mutex + (index + 1) % cfg->count};
	const t_time			time = cfg->time;
	const t_philo			philo = {.index = index, .eat_count = cfg->eat_count,
		.time_now = &cfg->time_now, .time = time, .death_id = &cfg->death_id,
		.lfork = forks[0], .rfork = forks[1]};

	cfg->death_id = 0;
	pthread_create(cfg->threads + index, NULL, philo_start, (void *) &philo);
	while (cfg->death_id == 0)				// Waits for thread to confirm it has copied the struct
			usleep(FT_UPDATE_INTERVAL);
	return (0);
}

// Returns: 0) OK, 1) Failure (P)
int	sim_init(int argc, const char **argv, t_shared_cfg *shared_cfg)
{
	size_t	i;

	if (stt_input_validation(argc, argv, shared_cfg) != 0)
		return (1);
	i = 0;
	while (i < shared_cfg->count)
		pthread_mutex_init(shared_cfg->mutex + i++, NULL);
	i = 0;
	while (i < shared_cfg->count)
		stt_let_there_be_life(i++, shared_cfg);
	shared_cfg->death_id = SIZE_MAX;
	return (0);
}
