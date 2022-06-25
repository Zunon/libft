/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:28:38 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 09:35:05 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
