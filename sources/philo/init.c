/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:04:26 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/01 14:30:21 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <pthread.h>
#include "philosophers.h"

static
int	stt_let_there_be_life(size_t index, t_sim_cfg *cfg)
{
	t_philo	*philo;

	philo = &(t_philo){.index = index, .params = cfg->params,
		.time_now = &cfg->time_now, .state = cfg->state + index,
		.forks = {cfg->mutex + index, cfg->mutex + (index + 1) % cfg->params.count}};
	cfg->prev_state[index] = e_idle;
	cfg->state[index] = e_death;
	pthread_create(cfg->threads + index, NULL, philo_start, (void *) philo);
	while (cfg->state[index] == e_death)				// Waits for thread to confirm it has copied the struct
			usleep(FT_UPDATE_INTERVAL);
	return (0);
}

// Returns: 0) OK, 1) Failure (P)
int	sim_init(int argc, const char **argv, t_sim_cfg *sim_cfg)
{
	size_t	i;

	if (input_validation(argc, argv, &sim_cfg->params) != 0)
		return (1);
	i = 0;
	while (i < sim_cfg->params.count)
		pthread_mutex_init(sim_cfg->mutex + i++, NULL);
	i = 0;
	while (i < sim_cfg->params.count)
		stt_let_there_be_life(i++, sim_cfg);
	return (0);
}
