/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_funcs3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:40:31 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 12:42:19 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[++i - 1])
		(*f)(i - 1, &s[i - 1]);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			length;
	unsigned int	i;
	char			*result;

	if (!s || !f)
		return (0);
	length = ft_strlen(s);
	result = malloc(length + 1);
	if (!result)
		return (0);
	i = -1;
	while (++i < length)
		result[i] = (*f)(i, s[i]);
	result[i] = 0;
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_i;
	size_t	end_i;

	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	start_i = 0;
	end_i = ft_strlen(s1) - 1;
	while (ft_strchr(set, (int)s1[start_i]))
		start_i++;
	while (ft_strchr(set, (int)s1[end_i]))
		end_i--;
	return (ft_substr(s1, start_i, end_i - start_i + 1));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	totlength;
	size_t	actual_length;
	char	*result;

	if (!s)
		return (0);
	totlength = ft_strlen(s);
	if (start >= totlength)
	{
		result = malloc(sizeof(char));
		if (!result)
			return (0);
		result[0] = 0;
		return (result);
	}
	if (totlength > len)
		actual_length = len;
	else
		actual_length = totlength - start;
	result = malloc((actual_length + 1) * sizeof(char));
	if (!result)
		return (0);
	ft_strlcpy(result, s + start, actual_length + 1);
	return (result);
}
