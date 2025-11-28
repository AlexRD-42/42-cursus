/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:04:26 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/28 16:45:37 by adeimlin         ###   ########.fr       */
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
	philos->death_time = 1000 * ((size_t) vars[1]);
	philos->eat_time = 1000 * ((size_t) vars[2]);
	philos->sleep_time = 1000 * ((size_t) vars[3]);
	philos->eat_count = (size_t) vars[4];
	return (0);
}

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
// Returns: 0) OK, -1) ARGCOUNT
static
int	stt_init_single(const char *str, t_shared_cfg *philos)
{
	size_t	i;
	int64_t	vars[5];

	i = 0;
	vars[4] = SIZE_MAX;
	while (i < 5 && *str >= '0' && *str <= '9')	// first char must be a number
	{
		vars[i] = ft_strtol(str);
		if (vars[i] < 0)
			return (-1);
		while (*str == ' ' || (*str >= 9 && *str <= 14))
			str++;
		i++;
	}
	if (*str != 0 || i < 4)
		return (-1);
	philos->count = (size_t) vars[0];
	philos->death_time = 1000 * ((size_t) vars[1]);
	philos->eat_time = 1000 * ((size_t) vars[2]);
	philos->sleep_time = 1000 * ((size_t) vars[3]);
	philos->eat_count = 1000 * (size_t) vars[4];
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

// Returns: 0) OK, 1) Failure (P)
int	sim_init(int argc, const char **argv, t_shared_cfg *philo_cfg, t_sim_cfg *sim_cfg)
{
	size_t	i;

	if (stt_input_validation(argc, argv, philo_cfg) != 0)
		return (1);
	i = 0;
	while (i < philo_cfg->count)
	{
		sim_cfg->philos[i].index = i;
		sim_cfg->philos[i].cfg = philo_cfg;
		pthread_mutex_init(philo_cfg->mutex + i, NULL);	// Always returns 0
		i++;
	}
	philo_cfg->death_id = SIZE_MAX;
	return (0);
}
