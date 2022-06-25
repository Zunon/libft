/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:01:04 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 12:03:24 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_atoi(const char *str)
{
	char	sign;
	size_t	i;
	int		result;
	int		dtc;

	result = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 0x09 && str[i] <= 0x0d) || str[i] == 0x20)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit((int)(str[i])))
	{
		dtc = result;
		result *= 10;
		result += (1 * sign) * (str[i] - '0');
		if ((dtc ^ result) & 0x80000000 && dtc != 0)
			return ((dtc < 0) - 1);
		i++;
	}
	return (result);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((char *)s)[i++] = 0;
}

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

static void	reset(size_t *m, size_t *n, long long int *startpos)
{
	*m = 0;
	*n = (size_t)(*startpos);
	*startpos = -1;
}
