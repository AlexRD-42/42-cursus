/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:04:26 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/27 16:21:29 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <pthread.h>
#include "philosophers.h"

// Returns: 0) OK, -1) ARGCOUNT
static
int	stt_init_multiple(const char **argv, t_philo_cfg *philos)
{
	size_t		i;
	const char	*str;
	int64_t		vars[5];

	i = 0;
	while (i < 5)
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
	philos->count = (uint32_t) vars[0];
	philos->eat_count = (uint32_t) vars[4];
	philos->death_time = (size_t) vars[1];
	philos->eat_time = (size_t) vars[2];
	philos->sleep_time = (size_t) vars[3];
	return (0);
}

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]
// Returns: 0) OK, -1) ARGCOUNT
static
int	stt_init_single(const char *str, t_philo_cfg *philos)
{
	size_t	i;
	int64_t	vars[5];

	i = 0;
	while (i < 5 && *str >= '0' && *str <= '9')	// first char must be a number
	{
		vars[i] = ft_strtol(str);
		if (vars[i] < 0)
			return (-1);
		while (*str == ' ' || (*str >= 9 && *str <= 14))
			str++;
		i++;
	}
	if (*str != 0)
		return (-1);
	philos->count = (uint32_t) vars[0];
	philos->eat_count = (uint32_t) vars[4];
	philos->death_time = (size_t) vars[1];
	philos->eat_time = (size_t) vars[2];
	philos->sleep_time = (size_t) vars[3];
	return (0);
}

// Returns: 0) OK, -1) ARGCOUNT, -2) EINVAL, -4) Philos exceeded count
static
int	stt_input_validation(int argc, const char **argv, t_philo_cfg *philos)
{
	int	rvalue;

	if (argc != 2 && argc != 4 && argc != 5)
	{
		write(STDERR_FILENO, "init_error: invalid argument count\n", 35);
		return (-1);
	}
	if (argc == 2)
		rvalue = stt_init_single(argv[1], philos);
	else
		rvalue = stt_init_multiple(argv, philos);
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

// Returns: SIZE_MAX) Failure (P), !SIZE_MAX) OK
void	*philo_init(int argc, const char **argv)
{
	static t_philo_cfg		cfg;
	static t_philo			philos[FT_MAX_PHILO];
	static pthread_t		threads[FT_MAX_PHILO];
	static pthread_mutex_t	mutex[FT_MAX_PHILO];
	size_t					i;

	if (stt_input_validation(argc, argv, &cfg) != 0)
		return (NULL);
	i = 0;
	while (i < cfg.count)
	{
		philos[i].index = i;
		philos[i].cfg = &cfg;
		pthread_mutex_init(mutex + i, NULL);	// Always returns 0
		i++;
	}
	cfg.philos = &philos;
	cfg.mutex = &mutex;
	cfg.threads = &threads;
	return (&cfg);
}
