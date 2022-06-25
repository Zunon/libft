/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_funcs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 13:33:22 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 12:38:31 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	word_len(char const *str, char sep)
{
	int	n;

	n = 0;
	while (str[n] && str[n] != sep)
		n++;
	return (n);
}

int	count_words(char const *str, char sep)
{
	if (!*str)
		return (0);
	while (*str && *str == sep)
		str++;
	if (!*str)
		return (0);
	while (*str && *str != sep)
		str++;
	if (!*str)
		return (1);
	else
		return (1 + count_words(str, sep));
}

char	**returner(char const *str)
{
	char	**result;

	if (!str)
	{
		result = malloc(sizeof(char *));
		if (!result)
			return (0);
		result[0] = 0;
		return (result);
	}
	else
	{
		result = malloc(sizeof(char *) * 2);
		if (!result)
			return (0);
		result[0] = ft_strdup(str);
		result[1] = 0;
		return (result);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;

	if (!s || !*s)
		return (returner(0));
	if (!c)
		return (returner(s));
	words = count_words(s, c);
	i = 0;
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (0);
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		result[i++] = ft_substr(s, 0, word_len(s, c));
		s += word_len(s, c);
	}
	result[i] = 0;
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return ((char *)s2);
	else if (!s2)
		return ((char *)s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (0);
	result[0] = 0;
	ft_strlcat(result, s1, len1 + len2 + 1);
	ft_strlcat(result, s2, len1 + len2 + 1);
	return (result);
}
