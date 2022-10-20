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

unsigned int	give_color_texture_up_right(t_fenetre *d,
	int x, int y, double angle)
{
	char	*dest;

	(void)angle;
	if (d->inters == d->xi)
		dest = d->tmp4_xpm + (y * d->size4_xpm + x * (d->bpp4_xpm / 8));
	else
		dest = d->tmp2_xpm + (y * d->size2_xpm + x * (d->bpp2_xpm / 8));
	return (*(unsigned int *)dest);
}

unsigned int	give_color_texture(t_fenetre *d, int x, int y, double angle)
{
	unsigned int	color;

	angle = check_angle(angle);
	if (angle >= 0 && angle < M_PI / 2)
		color = give_color_texture_down_left(d, x, y, angle);
	if (angle >= M_PI / 2 && angle < M_PI)
		color = give_color_texture_down_right(d, x, y, angle);
	if (angle < 3 * (M_PI / 2) && angle >= M_PI)
		color = give_color_texture_up_left(d, x, y, angle);
	if (angle >= (3 * M_PI / 2) || (angle >= (2 * M_PI)))
		color = give_color_texture_up_right(d, x, y, angle);
	return (color);
}

void	give_line_coord(t_fenetre *d, double angle)
{
	double	xi;
	double	yi;
	double	yn;

	yn = 64 - (d->py - ((int)(d->py / 64) * 64));
	yi = d->py + yn;
	xi = d->px + (yn / tan(angle));
	while ((xi < 64 * d->col && yi < 64 * d->ligne)
		&& d->map[((int)yi / 64)][((int)xi / 64)] != '1')
	{
		yi += 64;
		xi += 64 / tan(angle);
	}
	d->xi = (int)xi;
	d->disth = hypot((xi - d->px), (yi - d->py));
}

void	give_vert_coord(t_fenetre *d, double angle)
{
	double	xi;
	double	yi;
	double	yn;

	yn = 64 - (d->px - ((int)(d->px / 64) * 64));
	xi = d->px + yn;
	yi = d->py + (yn * tan(angle));
	while ((xi < 64 * d->col && yi < 64 * d->ligne)
		&& (d->map[(int)yi / 64][(int)xi / 64] != '1'))
	{
		xi += 64;
		yi += (64 * tan(angle));
	}
	d->yi = (int)yi;
	d->distv = (hypot((xi - d->px), (yi - d->py)));
}

void	give_line_coordd(t_fenetre *d, double angle)
{
	double	xi;
	double	yi;
	double	yn;

	yn = 64 - (d->py - ((int)(d->py / 64) * 64));
	yi = d->py + yn;
	xi = (d->px + (yn / tan(angle)));
	while ((xi > 0 && yi < 64 * d->ligne)
		&& d->map[((int)yi / 64)][((int)xi / 64)] != '1')
	{
		yi += 64;
		xi += 64 / tan(angle);
	}
	d->xi = (int)xi;
	d->disthh = hypot((xi - d->px), (yi - d->py));
}
