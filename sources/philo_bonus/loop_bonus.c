/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:36:15 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/05 15:00:50 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <philosophers_bonus.h>

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
		sem_wait(ph.sem);
		if (stt_change_state(e_fork0, &ph, 0))
			return (1);
		sem_wait(ph.sem);
		if (stt_change_state(e_fork1, &ph, 0))
			return (1);
		if (stt_change_state(e_eat, &ph, ph.params.eat))
			return (1);
		ph.params.eat_count--;
		sem_post(ph.sem);
		sem_post(ph.sem);
		if (stt_change_state(e_sleep, &ph, ph.params.sleep))
			return (1);
		if (stt_change_state(e_idle, &ph, 0))
			return (1);
	}
	stt_change_state(e_done, &ph, 0);
	return (0);
}

int	philo_start(size_t index, t_params params, const char *sem_name)
{
	int				rvalue;
	t_philo			ph;
	t_thread_cfg	cfg;
	pthread_t		thread_id;
	sem_t			*sem;

	cfg.index = index;
	cfg.params = params;
	cfg.time_now = 0;
	cfg.state = e_idle;
	cfg.last_meal = 0;
	sem = sem_open(sem_name, 0);
	if (sem == SEM_FAILED)
		return (1);
	ph = (t_philo){cfg.index, cfg.params, &cfg.time_now, &cfg.last_meal, &cfg.state, sem};
	pthread_create(&thread_id, NULL, monitor_start, (void *) &cfg);
	pthread_detach(thread_id);
	while (cfg.time_now == 0)
		usleep(FT_UPDATE_INTERVAL);
	if (ph.index & 1)
		update_clock(ph.params.eat / 2, ph.time_now);
	rvalue = stt_philo_main(ph);
	while (true)
		;
	return (rvalue);
}
