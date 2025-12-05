/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:18:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/04 18:29:23 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "philosophers.h"
#include "philosophers_common.h"

static inline
int	stt_must_eat(atomic_long *last_meal, long death, long eat, const atomic_long *time_now)
{
	const long	time_to_eat = 2 * eat + 50000;
	const long	time_remaining = death - (*time_now - *last_meal);

	if (time_remaining <= time_to_eat)
		return (1);
	usleep(FT_UPDATE_INTERVAL);
	return (0);
}

static
int	stt_philo_main(t_philo ph, bool priority)
{
	while (ph.params.eat_count > 0)
	{
		if (priority == false && !stt_must_eat(ph.last_meal, ph.params.death, ph.params.eat, ph.time_now))
			continue ;
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
		priority = !priority;
	}
	change_state(e_done, ph.state, ph.time_now, 0);
	return (0);
}

void	*philo_start(void *varg)
{
	t_philo	philo;
	bool	priority;

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
	priority = !!(philo.index & 1);
	stt_philo_main(philo, priority);
	return (NULL);
}
