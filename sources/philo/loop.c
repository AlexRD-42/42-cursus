/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:18:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/04 09:43:41 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "philosophers.h"

static
int	stt_philo_main(t_philo ph)
{
	while (ph.params.eat_count > 0)
	{
		pthread_mutex_lock(ph.forks[ph.index & 1]);
		if (change_state(e_fork0, ph.state, ph.time_now, 0))
			return (1);
		pthread_mutex_lock(ph.forks[!(ph.index & 1)]);
		if (change_state(e_fork1, ph.state, ph.time_now, 0))
			return (1);
		if (change_state(e_eat, ph.state, ph.time_now, ph.params.eat))
			return (1);
		ph.params.eat_count--;
		pthread_mutex_unlock(ph.forks[0]);
		pthread_mutex_unlock(ph.forks[1]);
		if (change_state(e_sleep, ph.state, ph.time_now, ph.params.sleep))
			return (1);
		if (change_state(e_idle, ph.state, ph.time_now, 0))
			return (1);
	}
	change_state(e_done, ph.state, ph.time_now, 0);
	return (0);
}

void	*philo_start(void *varg)
{
	t_philo	philo;

	philo = *(t_philo *)varg;
	*philo.state = e_idle;
	while (*philo.time_now == 0)
		usleep(FT_UPDATE_INTERVAL);
	if (philo.forks[0] == philo.forks[1])
	{
		pthread_mutex_lock(philo.forks[0]);
		change_state(e_fork0, philo.state, philo.time_now, 0);
		return (NULL);
	}
	stt_philo_main(philo);
	return (NULL);
}
