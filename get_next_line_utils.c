/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd-agnes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:19:34 by fd-agnes          #+#    #+#             */
/*   Updated: 2021/01/27 15:01:36 by fd-agnes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int			i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;

	if (dst == NULL && src == NULL)
	{
		return (NULL);
	}
	i = 0;
	if ((unsigned char *)dst > (unsigned char *)src)
	{
		while (len-- > 0)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

char		*join_str(char const *s1, char const *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	size_t		stot_len;
	char		*result;

	if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	stot_len = len_s1 + len_s2 + 1;
	if (!(result = malloc(sizeof(char) * stot_len)))
		return (0);
	ft_memmove(result, s1, len_s1);
	ft_memmove(result + len_s1, s2, len_s2);
	result[stot_len - 1] = '\0';
	free((char *)s1);
	return (result);
}

int			ft_return(char *str)
{
	int			i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
