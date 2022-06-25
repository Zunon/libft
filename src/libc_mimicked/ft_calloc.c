/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 22:23:47 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 09:37:47 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*area;
	size_t			total_size;
	size_t			i;

	total_size = size * count;
	i = 0;
	area = malloc(total_size);
	if (!area)
		return (0);
	while (i < total_size)
		area[i++] = 0;
	return ((void *)area);
}
