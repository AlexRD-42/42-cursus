/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/28 18:28:07 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# ifndef FT_MAX_PHILO
#  define FT_MAX_PHILO 256
# endif

// In microseconds
# ifndef FT_UPDATE_INTERVAL
#  define FT_UPDATE_INTERVAL 8
# endif

# include <stdint.h>
# include <stddef.h>
# include <stdatomic.h>
# include <pthread.h>

typedef struct s_time
{
	const long			death;
	const long			eat;
	const long			sleep;
	const atomic_long	*real;
}	t_time;

typedef struct s_philo
{
	const size_t	index;
	const size_t	eat_count;
	const t_time	time;
	union
	{
		pthread_mutex_t	*forks[2];
		struct
		{
			pthread_mutex_t	*lfork;
			pthread_mutex_t	*rfork;	
		};
	};
	// pthread_mutex_t	*lfork;
	// pthread_mutex_t	*rfork;
}	t_philo;

// 40 bytes per fork
typedef struct s_shared_cfg
{
	size_t					count;
	size_t					eat_count;
	t_time					time;					// Read by philos, written by main				
	volatile atomic_size_t	death_id;				// Read by main, written by philos
	pthread_mutex_t			mutex[FT_MAX_PHILO];	// Wtf, 10 kb?
}	t_shared_cfg;

// 16 bytes per philo
typedef struct s_philo_cfg
{
	size_t			index;
	t_shared_cfg	*cfg;
}	t_philo_cfg;

// 24 bytes per philo
typedef struct s_sim_cfg
{
	pthread_t	threads[FT_MAX_PHILO];
	t_philo_cfg	philos[FT_MAX_PHILO];
}	t_sim_cfg;

enum e_philo_state
{
	e_sleep = 0,
	e_idle = 1,
	e_eat = 2
};

int64_t	ft_strtol(const char *str);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t length);
int		sim_init(int argc, const char **argv, t_shared_cfg *philo_cfg, t_sim_cfg *sim_cfg);
char	*ft_itoa_stack(int64_t number, char *ptr);

#endif
