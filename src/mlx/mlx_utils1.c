/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:37:16 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 13:45:37 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_point	*make_hex_verts(int side, t_point center)
{
	t_point	center;
	double	cospi6;

	cospi6 = sqrt(3) / 2;
	return ((t_point [6]){
		(t_point){center.x, center.y - side},
		(t_point){center.x + (cospi6 * side), center.y - (side / 2)},
		(t_point){center.x + (cospi6 * side), center.y + (side / 2)},
		(t_point){center.x, center.y + side},
		(t_point){center.x - (cospi6 * side), center.y + (side / 2)},
		(t_point){center.x - (cospi6 * side), center.y - (side / 2)}
	});
}

void	put_hexagon(t_data *data, int side, t_color color)
{
	t_point	*vertices;
	t_point	center;
	t_line	*edges;
	int		i;

	center = (t_point){data->width / 2, data->height / 2};
	vertices = make_hex_verts(side, center);
	i = -1;
	edges = (t_line [6]){
		(t_line){vertices[0], vertices[1]},
		(t_line){vertices[1], vertices[2]},
		(t_line){vertices[3], vertices[2]},
		(t_line){vertices[4], vertices[3]},
		(t_line){vertices[5], vertices[4]},
		(t_line){vertices[5], vertices[0]}
	};
	i = 0;
	while (i < 6)
		put_line(data, &edges[i++], color);
}

void	put_grad_vertical(t_data *data, t_color *colors, double begin,
	double end)
{
	double	j;
	t_color	top_clr;
	t_color	bot_clr;

	top_clr = colors[0];
	bot_clr = colors[1];
	j = begin;
	while (j < end)
	{
		put_line(data, &(t_line){{0, j * data->height}, {data->width, j
			* data->height}}, mix_colors(top_clr, bot_clr, (j - begin)
				/ (end - begin)));
		j += (end - begin) / data->height;
	}
}

void	put_grad_horizontal(t_data *data, t_color *colors, double begin,
	double end)
{
	double	j;
	t_color	top_clr;
	t_color	bot_clr;

	top_clr = colors[0];
	bot_clr = colors[1];
	j = begin;
	while (j < end)
	{
		put_line(data, &(t_line){{j * data->width, 0}, {j * data->width,
			data->height}}, mix_colors(top_clr, bot_clr, (j - begin)
				/ (end - begin)));
		j += (end - begin) / data->width;
	}
}
