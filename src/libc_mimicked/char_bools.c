/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_bools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:06:31 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 11:20:06 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_bool	ft_isalnum(char c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

t_bool	ft_isalpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

t_bool	ft_isascii(char c)
{
	return (c >= 0x00 && c <= 0x7F);
}

t_bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

t_bool	ft_isprint(char c)
{
	return (c >= ' ' && c <= '~');
}
