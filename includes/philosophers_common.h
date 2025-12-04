/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_common.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:10:29 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/04 14:24:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_COMMON_H
# define PHILOSOPHERS_COMMON_H

# include <stdint.h>
# include <stddef.h>
# include <stdatomic.h>
# include <unistd.h>

# ifndef FT_MAX_PHILO
#  define FT_MAX_PHILO 256
# endif

# ifndef FT_LAG_COMPENSATION
#  define FT_LAG_COMPENSATION 5000
# endif

# ifndef FT_UPDATE_INTERVAL
#  define FT_UPDATE_INTERVAL 8
# endif

typedef struct s_params
{
	size_t	count;
	long	death;
	long	eat;
	long	sleep;
	long	eat_count;
}	t_params;

enum e_philo_state
{
	e_death = 0,
	e_idle = 1u,
	e_fork0 = 2u,
	e_fork1 = 3u,
	e_eat = 4u,
	e_sleep = 5u,
	e_done = 6u
};

int			init_params(int argc, const char **argv, t_params *philos);
int			change_state(uint8_t new_state, atomic_uchar *state, const atomic_long *tnow, long delay);
size_t		ft_strlen(const char *str);
char		*ft_strlcpy(char *restrict dst, const char *restrict src, size_t dst_size);
int64_t		ft_strtol(const char *str);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t length);
char		*ft_itoa_stt(int64_t number);
char		*ft_itoa_r(int64_t number, char *ptr);
ssize_t		ft_writev(int fd, const char **vec, char endl);
const char	**ft_strvcpy(char **restrict wdst, const char **restrict vec, char *restrict end);

#endif