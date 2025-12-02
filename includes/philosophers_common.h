/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_common.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:10:29 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 13:42:26 by adeimlin         ###   ########.fr       */
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

// In microseconds
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
	e_idle = 1,
	e_fork0 = 2,
	e_fork1 = 3,
	e_eat = 4,
	e_sleep = 5,
	e_done = 6
};

ssize_t	ft_putnbr_fd(int64_t number, int fd);

int			init_params(int argc, const char **argv, t_params *philos);
size_t		ft_strlen(const char *str);
char		*ft_strlcpy(char *restrict dst, const char *restrict src, size_t dst_size);
int64_t		ft_strtol(const char *str);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t length);
char		*ft_itoa_stt(int64_t number);
char		*ft_itoa_r(int64_t number, char *ptr);
ssize_t		ft_writev(int fd, const char **vec, char endl);
const char	**ft_strvcpy(char **restrict wdst, const char **restrict vec, char *restrict end);

#endif