#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

size_t	ft_strlen1(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

size_t	ft_strlcat0(char *dst, const char *src, size_t dst_size)
{
	char	*odst;

	odst = dst;
	while (dst_size > 0 && *dst != 0)
	{
		dst++;
		dst_size--;
	}
	return (dst - odst + ft_strlcpy(dst, src, dst_size));
}

size_t	ft_strlcat1(char *dst, const char *src, size_t dst_size)
{
	char	*odst;

	odst = dst;
	while (dst_size > 0 && *dst != 0)
	{
		dst++;
		dst_size--;
	}
	if (dst_size == 0)
		return (dst - odst + ft_strlen(src));
	while (*src != 0 && dst_size > 1) 
	{
		*dst++ = *src++;
		dst_size--;
	}
	*dst = 0;
	return (dst - odst + ft_strlen(src)); 
}

size_t	ft_strlcat2(char *dst, const char *src, size_t dst_size)
{
	size_t	cat_len;

	cat_len = 0;
	while (cat_len < dst_size && *dst != 0)
	{
		dst++;
		cat_len++;
	}
	if (dst_size == 0)
		return (cat_len + ft_strlen(src));
	cat_len += ft_strlcpy(dst, src, dst_size - cat_len);
	return (cat_len); 
}
size_t	ft_strlcat3(char *dst, const char *src, size_t dst_size)
{
	size_t	cat_len;

	cat_len = 0;
	while (cat_len < dst_size && *dst != 0)
	{
		dst++;
		cat_len++;
	}
	if (dst_size == 0)
		return (cat_len + ft_strlen(src));
	while (*src != 0 && cat_len < dst_size - 1) 
	{
		*dst++ = *src++;
		cat_len++;
	}
	*dst = 0;
	while (*src++ != 0)
		cat_len++;
	return (cat_len); 
}

size_t	ft_strlcat4(char *dst, const char *src, size_t dst_size)
{
	const char	*odst;
	size_t		n;
	size_t		src_len;
	size_t		dst_len;

	odst = dst;
	src_len = ft_strlen(src);
	n = dst_size;
	while (n-- != 0 && *dst != 0)
		dst++;
	dst_len = dst - odst;
	n = dst_size - dst_len;
	if (n == 0)
		return(dst_len + src_len);
	while (*src != 0 && --n > 0)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = 0;
	return(dst_len + src_len);
}

size_t	ft_strlcpy1(char *dst, const char *src, size_t dst_size)
{
	size_t	i;
	size_t	src_size;

	src_size = ft_strlen(src);
	if (dst_size == 0)
		return (src_size);
	i = 0;
	while (i < src_size && i < dst_size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_size);
}

size_t	ft_strlcpy2(char *dst, const char *src, size_t dsize)
{
	const char *osrc = src;
	size_t nleft = dsize;

	/* Copy as many bytes as will fit. */
	if (nleft != 0) 
	{
		while (--nleft != 0) 
		{
			if ((*dst++ = *src++) == 0)
				break;
		}
	}
	/* Not enough room in dst, add NUL and traverse rest of src. */
	if (nleft == 0) {
		if (dsize != 0)
			*dst = 0;		/* NUL-terminate dst */
		while (*src++)
			;
	}

	return(src - osrc - 1);	/* count does not include NUL */
}

char	**ft_split1(char const *s, char c)
{
	char const	*next;
	char		**str_array;
	size_t		i;
	size_t		k;

	i = 0;
	k = 0;
	str_array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	while (s[i] != 0)
	{
		if ((s[i] == c && s[i + 1] != c) || (i == 0 && s[0] != c))
		{
			next = ft_strchr(s + i + 1, c);
			if (next == NULL)
				next = s + ft_strlen(s);
			str_array[k++] = ft_substr(s, i + (i != 0), next - s - i - (i != 0));
			i = next - s;
		}
		else
			i++;
	}
	str_array[k] = 0;
	return(str_array);
}

char	**ft_split2(char const *s, char c)
{
	char const	*next;
	char		**str_array;
	size_t		i;

	i = 0;
	next = NULL;
	str_array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	while (*s != 0)
	{
		if ((*s == c && *(s + 1) != c) || (next == NULL && s[0] != c))
		{
			next = ft_strchr(s + 1, c);
			if (next == NULL)
				next = s + ft_strlen(s);
			str_array[i++] = ft_substr(s, 0, next - s);
		}
		else
			s++;
	}
	str_array[i] = 0;
	return(str_array);
}

char	**ft_split3(char const *s, char c)
{
	char		*next;
	char		**str_array;
	size_t		i;
	int64_t		len;

	i = 0;
	str_array = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	while (s != NULL && *s != 0)
	{
		len = ft_strchr(s + 1, c) - s;
		if (len < 0)
			str_array[i++] = ft_substr(s, 0, ft_strlen(s));
		else if (len > 1)
			str_array[i++] = ft_substr(s + (*s == c), 0, len - (*s == c));
		s += len;
	}
	str_array[i] = 0;
	return(str_array);
}