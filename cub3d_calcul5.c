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

void	give_vert_coordd(t_fenetre *d, double angle)
{
	double	xi;
	double	yi;
	double	yn;

	yn = (d->px - ((int)(d->px / 64) * 64));
	xi = d->px - yn;
	yi = d->py - (yn * tan(angle));
	while ((xi > 0.0 && yi < 64 * d->ligne)
		&& (d->map[((int)yi / 64)][((int)xi / 64) - 1] != '1'))
	{
		xi -= 64;
		yi -= (64 * tan(angle));
	}
	d->yi = (int)yi;
	d->distvv = (hypot((xi - d->px), (yi - d->py)));
}

void	give_line_coorddd(t_fenetre *d, double angle)
{
	double	xi;
	double	yi;
	double	yn;

	yn = (d->py - ((int)(d->py / 64) * 64));
	yi = d->py - yn;
	xi = (d->px - (yn / tan(angle)));
	while ((xi > 0.0 && yi > 0.0)
		&& d->map[((int)yi / 64) - 1][((int)xi / 64)] != '1')
	{
		yi -= 64;
		xi -= 64 / tan(angle);
	}
	d->xi = (int)xi;
	d->disthhh = hypot((xi - d->px), (yi - d->py));
}

void	give_vert_coorddd(t_fenetre *d, double angle)
{
	double	xi;
	double	yi;
	double	yn;

	yn = (d->px - ((int)(d->px / 64) * 64));
	xi = d->px - yn;
	yi = d->py - (yn * tan(angle));
	while ((xi > 0.0 && yi > 0.0)
		&& (d->map[((int)yi / 64)][((int)xi / 64) - 1] != '1'))
	{
		xi -= 64;
		yi -= (64 * tan(angle));
	}
	d->yi = (int)yi;
	d->distvvv = (hypot((xi - d->px), (yi - d->py)));
}

void	give_line_coordddd(t_fenetre *d, double angle)
{
	double	xi;
	double	yi;
	double	yn;

	yn = (d->py - ((int)(d->py / 64) * 64));
	yi = d->py - yn;
	xi = (d->px - (yn / tan(angle)));
	while ((xi < 64.0 * d->col && yi > 0.0)
		&& d->map[((int)yi / 64) - 1][((int)xi / 64)] != '1')
	{
		yi -= 64;
		xi -= 64 / tan(angle);
	}
	d->xi = (int)xi;
	d->disthhhh = hypot((xi - d->px), (yi - d->py));
}

void	give_vert_coordddd(t_fenetre *d, double angle)
{
	double	xi;
	double	yi;
	double	yn;

	yn = 64 - (d->px - ((int)(d->px / 64) * 64));
	xi = d->px + yn;
	yi = d->py + (yn * tan(angle));
	while ((xi < 64.0 * d->col && yi > 0.0)
		&& (d->map[((int)yi / 64)][((int)xi / 64)] != '1'))
	{
		xi += 64;
		yi += (64 * tan(angle));
	}
	d->yi = (int)yi;
	d->distvvvv = (hypot((xi - d->px), (yi - d->py)));
}
