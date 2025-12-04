/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:36:15 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/04 11:34:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <philosophers_bonus.h>

static
int	stt_philo_main(t_philo ph)
{
	while (ph.params.eat_count > 0)
	{
		sem_wait(ph.sem);
		if (change_state(e_fork0, ph.state, ph.time_now, 0))
			return (1);
		sem_wait(ph.sem);
		if (change_state(e_fork1, ph.state, ph.time_now, 0))
			return (1);
		if (change_state(e_eat, ph.state, ph.time_now, ph.params.eat))
			return (1);
		ph.params.eat_count--;
		sem_post(ph.sem);
		sem_post(ph.sem);
		if (change_state(e_sleep, ph.state, ph.time_now, ph.params.sleep))
			return (1);
		if (change_state(e_idle, ph.state, ph.time_now, 0))
			return (1);
	}
	change_state(e_done, ph.state, ph.time_now, 0);
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
	sem = sem_open(sem_name, 0);
	if (sem == SEM_FAILED)
		return (1);
	pthread_create(&thread_id, NULL, monitor_start, (void *) &cfg);
	pthread_detach(thread_id);
	ph = (t_philo){cfg.index, cfg.params, &cfg.time_now, &cfg.state, sem};
	while (cfg.time_now == 0)
		usleep(FT_UPDATE_INTERVAL);
	rvalue = stt_philo_main(ph);
	while (true)
		;
	return (rvalue);
}
