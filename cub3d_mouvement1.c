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

void	mouvement_up(t_fenetre *d)
{
	d->py -= sin(d->pa) * 10;
	d->px -= cos(d->pa) * 10;
}

void	mouvement_down(t_fenetre *d)
{
	d->py += sin(d->pa) * 10;
	d->px += cos(d->pa) * 10;
}

void	mouvement_left(t_fenetre *d)
{
	d->py += sin(d->pa + M_PI / 2) * 10;
	d->px += cos(d->pa + M_PI / 2) * 10;
}

void	mouvement_right(t_fenetre *d)
{
	d->py += sin(d->pa - M_PI / 2) * 10;
	d->px += cos(d->pa - M_PI / 2) * 10;
}

void	rotation_left(t_fenetre *d)
{
	d->pa += M_PI / 180 * 2;
	if (d->pa >= M_PI * 2)
		d->pa -= 2 * M_PI;
	d->pdx = cos(d->pa);
	d->pdy = sin(d->pa);
}
