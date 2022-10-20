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

void	rotation_right(t_fenetre *d)
{
	d->pa -= M_PI / 180 * 2;
	if (d->pa < 0)
		d->pa += 2 * M_PI;
	d->pdx = cos(d->pa);
	d->pdy = sin(d->pa);
}

int	kill_the_windows(t_fenetre *d)
{
	(void)d;
	mlx_destroy_window(d->id, d->win);
	exit(0);
	return (1);
}

int	key_press(int keycode, t_fenetre *s)
{
	if (keycode == 0)
		s->modeg = 1;
	if (keycode == 1)
		s->modeb = 1;
	if (keycode == 2)
		s->moded = 1;
	if (keycode == 13)
		s->modeh = 1;
	if (keycode == 123)
		s->modefg = 1;
	if (keycode == 124)
		s->modefd = 1;
	if (keycode == 53)
		s->modeesc = 1;
	return (1);
}

int	key_release(int keycode, t_fenetre *s)
{
	if (keycode == 0)
		s->modeg = 0;
	if (keycode == 1)
		s->modeb = 0;
	if (keycode == 2)
		s->moded = 0;
	if (keycode == 13)
		s->modeh = 0;
	if (keycode == 123)
		s->modefg = 0;
	if (keycode == 124)
		s->modefd = 0;
	if (keycode == 53)
		s->modeesc = 0;
	return (1);
}

int	all_mouvement(t_fenetre *d)
{
	if (d->modeb == 1)
		mouvement_up(d);
	if (d->modeh == 1)
		mouvement_down(d);
	if (d->modeg == 1)
		mouvement_left(d);
	if (d->moded == 1)
		mouvement_right(d);
	if (d->modefg == 1)
		rotation_left(d);
	if (d->modefd == 1)
		rotation_right(d);
	if (d->modeesc == 1)
		exit(0);
	return (0);
}
