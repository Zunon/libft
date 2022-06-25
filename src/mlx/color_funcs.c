/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:25:18 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 13:25:32 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	get_color(t_color color)
{
	return (color.blue + (color.green << 8) + (color.red << 16)
		+ (color.alpha << 24));
}

t_color	make_color(int color)
{
	return ((t_color){color >> 24, color >> 16, color >> 8, color});
}

t_color	mix_colors(t_color from, t_color to, double amount)
{
	return ((t_color){
		(to.alpha - from.alpha) * amount + from.alpha,
		(to.red - from.red) * amount + from.red,
		(to.green - from.green) * amount + from.green,
		(to.blue - from.blue) * amount + from.blue
	});
}

t_color	add_shade(t_color color, double amount)
{
	t_color	black;

	black = (t_color){0, 0, 0, 0};
	return (mix_colors(color, black, amount));
}

t_color	get_opposite(t_color color)
{
	return ((t_color){
		0xFF - color.alpha,
		0xFF - color.red,
		0xFF - color.green,
		0xFF - color.blue
	});
}
