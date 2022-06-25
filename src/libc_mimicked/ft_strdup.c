/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:39:10 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 09:37:01 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*newstr;

	i = 0;
	len = ft_strlen(s1);
	newstr = malloc(len + 1);
	if (!newstr)
		return (0);
	while (i < (len + 1))
	{
		newstr[i] = s1[i];
		i++;
	}
	return (newstr);
}
