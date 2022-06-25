/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:52:38 by kalmheir          #+#    #+#             */
/*   Updated: 2022/06/25 09:34:09 by kalmheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 2048
#define HEIGHT 1152

enum e_event {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_color {
	unsigned char	alpha;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_color;

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_line {
	t_point	start;
	t_point	end;
}	t_line;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlxd {
	void	*mlx;
	void	*window;
}	t_mlxd;

// int close(int keycode, t_mlxd *data)
// {
// 	if (keycode == 0x35)
// 	{
// 		mlx_destroy_window(data->mlx, data->window);
// 	}
// 	return (0);
// }

int	get_color(t_color color)
{
	return (color.blue + (color.green << 8) + (color.red << 16) + (color.alpha << 24));
}

t_color make_color(int color)
{
	return ((t_color){color >> 24, color >> 16, color >> 8, color});
}

t_color mix_colors(t_color from, t_color to, double amount)
{
	return (t_color){
		(to.alpha - from.alpha) * amount + from.alpha,
		(to.red - from.red) * amount + from.red,
		(to.green - from.green) * amount + from.green,
		(to.blue - from.blue) * amount + from.blue
	};
}

t_color add_shade(t_color color, double amount)
{
	t_color BLACK = (t_color){0, 0, 0, 0};
	return mix_colors(color, BLACK, amount);
}

t_color get_opposite(t_color color)
{
	return (t_color){
		0xFF - color.alpha,
		0xFF - color.red,
		0xFF - color.green,
		0xFF - color.blue
	};
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*((unsigned int *)dst) = color;
}

void	put_line(t_data *data, t_line *line, int color)
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

void	put_rect(t_data *data, int width, int height, int color)
{
	int		off_x;
	int		off_y;
	t_line	lines[4];
	int		i;

	off_x = WIDTH / 2 - width / 2;
	off_y = HEIGHT / 2 - height / 2;
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

void	put_iso_tri(t_data *data, int base, int height, int color)
{
	int		off_x;
	int		off_y;
	int		i;
	t_line	lines[4];

	off_x = WIDTH / 2 - base / 2;
	off_y = HEIGHT / 2 - height / 2;
	lines[0] = (t_line){{off_x, off_y + height}, {off_x + base, off_y
		+ height}};
	lines[1] = (t_line){{off_x, off_y + height}, {off_x + (base / 2), off_y}};
	lines[2] = (t_line){{off_x + (base / 2), off_y}, {off_x + base,
		off_y + height}};
	i = 0;
	printf("Hello\n");
	while (i < 3)
		put_line(data, &(lines[i++]), color);
}

void	put_circle(t_data *data, int radius, int color)
{
	double	i;

	i = 0;
	while (i < 2 * M_PI * radius)
	{
		put_pixel(data, WIDTH / 2 + radius * cos(i), HEIGHT / 2 + radius
			* sin(i), color);
		i += 0.1;
	}
}

void put_hexagon(t_data *data, int side, int color)
{
	t_point	*vertices;
	t_point	center;
	t_line	*edges;
	double	cospi6;
	int		i;

	cospi6 = sqrt(3) / 2;
	center = (t_point){WIDTH / 2, HEIGHT / 2};
	vertices = (t_point [6]){
		(t_point){center.x, center.y - side},
		(t_point){center.x + (cospi6 * side), center.y - (side / 2)},
		(t_point){center.x + (cospi6 * side), center.y + (side / 2)},
		(t_point){center.x, center.y + side},
		(t_point){center.x - (cospi6 * side), center.y + (side / 2)},
		(t_point){center.x - (cospi6 * side), center.y - (side / 2)},
	};
	i = -1;
	edges = (t_line [6]){
		(t_line){vertices[0],vertices[1]},
		(t_line){vertices[1],vertices[2]},
		(t_line){vertices[3],vertices[2]},
		(t_line){vertices[4],vertices[3]},
		(t_line){vertices[5],vertices[4]},
		(t_line){vertices[5],vertices[0]}
	};
	i = 0;
	while (i < 6)
		put_line(data, &edges[i++], color);
}

void put_grad_vertical(t_data *data, t_color top_clr, t_color bot_clr, double begin, double end)
{
	double j;

	j = begin;
	while (j < end)
	{
		put_line(data, &(t_line){{0, j * HEIGHT}, {WIDTH, j * HEIGHT}}, get_color(mix_colors(top_clr, bot_clr, (j - begin)/(end - begin))));
		j += (end-begin) / HEIGHT;
	}
}

void put_grad_horizontal(t_data *data, t_color top_clr, t_color bot_clr, double begin, double end)
{
	double j;

	j = begin;
	while (j < end)
	{
		put_line(data, &(t_line){{j * WIDTH, 0}, {j * WIDTH, HEIGHT}},  get_color(mix_colors(top_clr, bot_clr, (j - begin)/(end - begin))));
		j += (end - begin) / WIDTH;
	}
}

// int terminate()
// {
// 	exit(0);
// }

// int	main(void)
// {
// 	t_mlxd	mlx;
// 	t_data	img;
// 	double BOW = 0.16666666666;

// 	mlx.mlx = mlx_init();
// 	img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
// 			&img.line_length, &img.endian);
// 	mlx.window = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Hello, Rainbow!");
// 	put_grad_horizontal(&img, make_color(0x00FF0000), make_color(0x00FF7F00), 0, BOW);
// 	put_grad_horizontal(&img, make_color(0x00FF7F00), make_color(0x00FFFF00), BOW, BOW * 2);
// 	put_grad_horizontal(&img, make_color(0x00FFFF00), make_color(0x0000FF00), BOW * 2, BOW * 3);
// 	put_grad_horizontal(&img, make_color(0x0000FF00), make_color(0x000000FF), BOW * 3, BOW * 4);
// 	put_grad_horizontal(&img, make_color(0x000000FF), make_color(0x004B0082), BOW * 4, BOW * 5);
// 	put_grad_horizontal(&img, make_color(0x004B0082), make_color(0x009400D3), BOW * 5, BOW * 6);
// 	mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, 0, 0);
// 	mlx_hook(mlx.window, ON_KEYDOWN, 0, close, &mlx);
// 	mlx_hook(mlx.window, ON_DESTROY, 0, terminate, 0);
// 	mlx_loop(mlx.mlx);
// }
