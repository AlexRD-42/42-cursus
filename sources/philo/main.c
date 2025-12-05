/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/05 10:48:41 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "philosophers.h"

static
int	stt_let_there_be_life(size_t index, t_sim_cfg *cfg)
{
	t_philo		*philo;
	pthread_t	thread_id;

	philo = &(t_philo){.index = index, .params = cfg->params,
		.time_now = &cfg->time_now, .state = cfg->state + index,
		.last_meal = cfg->last_meal + index,
		.forks = {cfg->mutex + index,
		cfg->mutex + (index + 1) % cfg->params.count}};
	cfg->prev_state[index] = e_idle;
	cfg->state[index] = e_death;
	cfg->last_meal[index] = 0;
	pthread_create(&thread_id, NULL, philo_start, (void *) philo);
	pthread_detach(thread_id);
	while (cfg->state[index] == e_death)	// Waits for thread to confirm it has copied the struct
		usleep(FT_UPDATE_INTERVAL);
	return (0);
}

int			argc = 2;
// const char	*argv[2] = {NULL, "5 700 200 100"};
const char	*argv[2] = {NULL, "3 700 200 100"};

int	main(void)
{
	static t_sim_cfg	cfg;
	size_t				i;

	cfg.time_now = 0;
	if (init_params(argc, argv, &cfg.params) != 0)
		return (1);
	i = 0;
	while (i < cfg.params.count)
		pthread_mutex_init(cfg.mutex + i++, NULL);
	i = 0;
	while (i < cfg.params.count)
		stt_let_there_be_life(i++, &cfg);
	return (monitor_state(&cfg));
}
