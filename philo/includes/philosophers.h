/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:21:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/30 18:49:07 by adeimlin         ###   ########.fr       */
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
# include <unistd.h>

typedef struct s_time
{
	long	death;
	long	eat;
	long	sleep;
}	t_time;

typedef struct s_philo
{
	const size_t		index;
	size_t				eat_count;
	const atomic_long	*time_now;
	atomic_char			*state;
	const t_time		time;
	pthread_mutex_t		*forks[2];
}	t_philo;

// 40 bytes per fork
typedef struct s_shared_cfg
{
	size_t			count;
	size_t			eat_count;
	atomic_long		time_now;
	t_time			time;					// Read by philos, written by main				
	atomic_char		state[FT_MAX_PHILO];	// Read by main, written by philos
	char			prev_state[FT_MAX_PHILO];
	pthread_mutex_t	mutex[FT_MAX_PHILO];	// Wtf, 10 kb?
	pthread_t		threads[FT_MAX_PHILO];
}	t_shared_cfg;

enum e_philo_state
{
	e_death = 0,
	e_idle = 1,
	e_fork0 = 2,
	e_fork1 = 3,
	e_eat = 4,
	e_sleep = 5,
	e_done = 6
};

size_t		ft_strlen(const char *str);
char		*ft_strlcpy(char *restrict dst, const char *restrict src, size_t dst_size);
int64_t		ft_strtol(const char *str);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t length);
int			sim_init(int argc, const char **argv, t_shared_cfg *philo_cfg);
char		*ft_itoa_stt(int64_t number);
char		*ft_itoa_r(int64_t number, char *ptr);

ssize_t		ft_writev(int fd, const char **vec, char endl);
void		*philo_start(void *varg);

const	\
char	**ft_strvcpy(
				char **restrict wdst		/* Test */,
				const char **restrict vec,
				char *restrict end\
			);

#endif
