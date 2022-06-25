/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:52:38 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 13:52:04 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minilibx_mms_20191025_beta/mlx.h"
#include "../../libft.h"

void	put_pixel(t_data *data, int x, int y, t_color color)
{
	char	*dst;
	int		offset;

	if (x >= data->width || y >= data->height || x < 0 || y < 0)
		return ;
	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*((t_color *)dst) = color;
}

void	put_line(t_data *data, t_line *line, t_color color)
{
	double	i;
	double	length;
	double	slope;

	if (line->end.x - line->start.x != 0)
	{
		slope = (double)((line->end.y - line->start.y)) / (line->end.x
				- line->start.x);
		i = 0;
		length = (line->end.x - line->start.x);
		while (i < length)
		{
			put_pixel(data, i + line->start.x, (slope * i) + line->start.y,
				color);
			i += 0.1;
		}
		return ;
	}
	length = (line->end.y - line->start.y);
	i = 0;
	while (i < length)
	{
		put_pixel(data, line->start.x, line->start.y + i, color);
		i++;
	}
}

void	put_rect(t_data *data, int width, int height, t_color color)
{
	int		off_x;
	int		off_y;
	t_line	lines[4];
	int		i;

	off_x = data->width / 2 - width / 2;
	off_y = data->height / 2 - height / 2;
	lines[0] = (t_line){{off_x, off_y}, {off_x + width, off_y}};
	lines[1] = (t_line){{off_x + width, off_y}, {off_x + width, off_y
		+ height}};
	lines[2] = (t_line){{off_x, off_y}, {off_x, off_y + height}};
	lines[3] = (t_line){{off_x, off_y + height}, {off_x + width, off_y
		+ height}};
	i = 0;
	while (i < 4)
		put_line(data, &(lines[i++]), color);
}

void	put_iso_tri(t_data *data, int base, int height, t_color color)
{
	int		off_x;
	int		off_y;
	int		i;
	t_line	lines[4];

	off_x = data->width / 2 - base / 2;
	off_y = data->height / 2 - height / 2;
	lines[0] = (t_line){{off_x, off_y + height}, {off_x + base, off_y
		+ height}};
	lines[1] = (t_line){{off_x, off_y + height}, {off_x + (base / 2), off_y}};
	lines[2] = (t_line){{off_x + (base / 2), off_y}, {off_x + base,
		off_y + height}};
	i = 0;
	while (i < 3)
		put_line(data, &(lines[i++]), color);
}

void	put_circle(t_data *data, int radius, t_color color)
{
	double	i;

	i = 0;
	while (i < 2 * M_PI * radius)
	{
		put_pixel(data, data->width / 2 + radius * cos(i), data->height / 2
			+ radius * sin(i), color);
		i += 0.1;
	}
}
