/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:25:14 by whamoumi          #+#    #+#             */
/*   Updated: 2022/01/04 12:39:56 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawing_ceil_left_fov(t_fenetre *s, int x, int y)
{
	int	y_index;

	y_index = y;
	while (y_index > 0)
	{
		my_mlx_pixel_put(s, x, y_index, create_rgb(s->r_c, s->g_c, s->b_c));
		y_index--;
	}
}

void	drawing_floor_left_fov(t_fenetre *s, int x, int y)
{
	int	y_index;

	y_index = y;
	while (y_index < s->largeur)
	{
		my_mlx_pixel_put(s, x, y_index, create_rgb(s->r_f, s->g_f, s->b_f));
		y_index++;
	}
}

void	drawing_wall_left_fov(t_fenetre *s, int x, int y, double wall_height)
{
	int		y_index;
	double	texture_ratio;
	double	k;
	double	angle;

	k = 0;
	y_index = 0;
	angle = s->pa + ((s->longeur / 2 - x) * s->fov_angle);
	texture_ratio = (64 / wall_height);
	while (y_index < wall_height)
	{
		my_mlx_pixel_put(s, x, y + y_index,
			give_color_texture(s, s->inters % 64, k, angle));
		k += texture_ratio;
		y_index++;
	}
}

void	draw_left_fov(t_fenetre *s)
{
	double	r;
	double	u;
	double	angle;
	int		x;
	int		ywalls;

	angle = s->pa;
	x = s->longeur / 2;
	while (x > 0)
	{
		r = ray_draw(s, angle) * cos(angle - s->pa);
		u = ((64 / r) * s->projection);
		ywalls = (s->largeur / 2) - (u / 2);
		drawing_wall_left_fov(s, x, ywalls, u);
		drawing_ceil_left_fov(s, x, ywalls);
		drawing_floor_left_fov(s, x, (ywalls + u));
		angle += s->fov_angle;
		x--;
	}
}
