/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:28:17 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/30 22:41:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

// Print and putnbr
// Create a testing repo and make libft clean

size_t	ft_strlen(const char *str);
char	*ft_strfind(const char *str, const char *charset, uint8_t ref);
char	**ft_strvcpy(char **restrict wdst, const char **restrict vec, char *restrict end);

char	*ft_strlcpy(char *restrict dst, const char *restrict src, size_t dst_size);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
uint8_t	ft_ascii(const char c);

// ft_error and ft_write 
ssize_t	ft_writev(int fd, const char **vec, char endl); 
char	*ft_itoa_stt(int64_t number);
char	*ft_itoa_r(int64_t number, char *ptr);
int64_t	ft_strtol(const char *str);

void	*ft_memmove(void *vdst, const void *vsrc, size_t length);
void	*ft_memcpy(void *restrict vdst, const void *restrict vsrc, size_t length);
void	*ft_memset(void *vdst, const uint8_t byte, size_t length);
void	*ft_memchr(const void *vptr, uint8_t byte, size_t length);

int64_t	ft_memcmp(const void *vptr1, const void *vptr2, size_t length);

// swap