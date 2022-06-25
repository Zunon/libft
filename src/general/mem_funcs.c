/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:13:50 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 13:13:39 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memchr(const void *s, t_byte c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((t_byte *)s)[i] == (t_byte)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((t_byte *)s1)[i] != ((t_byte *)s2)[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return (((t_byte *)s1)[i] - ((t_byte *)s2)[i]);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	else if (dst == src)
		return (dst);
	else if (src < dst)
	{
		i = len;
		while (--i != __UINT64_MAX__)
			((t_byte *)dst)[i] = ((t_byte *)src)[i];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

void	*ft_memset(void *b, t_byte c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((t_byte *)b)[i] = c;
		i++;
	}
	return (b);
}
