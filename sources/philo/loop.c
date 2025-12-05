/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:18:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/05 14:50:59 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "philosophers.h"
#include "philosophers_common.h"

static
int	stt_change_state(uint8_t new_state, t_philo *ph, long delay)
{
	if (update_clock(0, ph->time_now))
		return (1);
	if (new_state == e_eat)
		*ph->last_meal = *ph->time_now;
	*ph->state = new_state;
	if (update_clock(delay, ph->time_now))
		return (1);
	return (0);
}

static inline
void	stt_delay_eating(t_philo *ph)
{
	const long	time_to_eat = ph->params.eat;
	const long	time_left = ph->params.death - (*ph->time_now - *ph->last_meal);
	const long	time_slack = time_left - time_to_eat;
	const long	time_margin = 20000;

	if (time_slack < time_margin || time_left > 3 * ph->params.eat)
		return ;
	update_clock(time_slack - time_margin, ph->time_now);
	return ;
}

static
int	stt_philo_main(t_philo ph)
{
	while (ph.params.eat_count > 0)
	{
		stt_delay_eating(&ph);
		pthread_mutex_lock(ph.forks[ph.index & 1]);
		if (stt_change_state(e_fork0, &ph, 0))
			return (1);
		pthread_mutex_lock(ph.forks[!(ph.index & 1)]);
		if (stt_change_state(e_fork1, &ph, 0))
			return (1);
		if (stt_change_state(e_eat, &ph, ph.params.eat))
			return (1);
		ph.params.eat_count--;
		pthread_mutex_unlock(ph.forks[0]);
		pthread_mutex_unlock(ph.forks[1]);
		if (stt_change_state(e_sleep, &ph, ph.params.sleep))
			return (1);
		if (stt_change_state(e_idle, &ph, 0))
			return (1);
	}
	stt_change_state(e_done, &ph, 0);
	return (0);
}

void	*philo_start(void *varg)
{
	t_philo	philo;

	philo = *(t_philo *)varg;
	*philo.state = e_idle;
	while (*philo.time_now == 0)
		usleep(FT_UPDATE_INTERVAL);
	*philo.last_meal = *philo.time_now;
	if (philo.index & 1)
		update_clock(philo.params.eat / 2, philo.time_now);
	if (philo.forks[0] == philo.forks[1])
	{
		pthread_mutex_lock(philo.forks[0]);
		stt_change_state(e_fork0, &philo, 0);
		return (NULL);
	}
	stt_philo_main(philo);
	return (NULL);
}
