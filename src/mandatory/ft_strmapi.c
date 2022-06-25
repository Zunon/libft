/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:14:48 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 09:35:15 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

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
