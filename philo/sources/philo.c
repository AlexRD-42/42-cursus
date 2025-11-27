/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:54:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/27 10:22:37 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <threads.h>
#include "philosophers.h"
#include <sys/time.h>

// number_of_philosophers
// time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
// update_clock?

static
int	p_sleep()
{
	
}

int	life_loop(size_t entity_id, size_t *values)
{
	static thread_local size_t	cur_values[4] = {0, 0, 0, 0};
	static thread_local size_t	ref_values[4] = {0, 0, 0, 0};
	static thread_local uint8_t	state = 0;

	if (values != NULL)
		ft_memcpy(ref_values, values + 1, sizeof(size_t) * 4);
	if (state == 1)
		return (0);

}
