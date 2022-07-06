/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolivar <ybolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:33:19 by ybolivar          #+#    #+#             */
/*   Updated: 2022/07/04 17:37:58 by ybolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

void	gnl_bzero(void *str, size_t len)
{
	unsigned char	*buf;

	buf = str;
	while (len--)
	{
		*buf++ = 0;
	}
}

void	*gnl_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size >= SIZE_MAX || count >= SIZE_MAX)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	gnl_bzero(ptr, (count * size));
	return (ptr);
}

char	*gnl_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != (char)c))
	{
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}

size_t	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*send;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	send = join;
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (send);
}
