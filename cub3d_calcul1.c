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

void	my_mlx_pixel_put(t_fenetre *d, int x, int y, int color)
{
	char	*dst;

	dst = d->tmp + (y * d->size + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

double	check_angle(double angle)
{
	double	new_angle;

	new_angle = angle;
	if (angle <= 0)
		new_angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		new_angle -= 2 * M_PI;
	if (!((angle <= 0) || angle > 2 * M_PI))
		new_angle = angle;
	return (new_angle);
}

unsigned int	give_color_texture_down_left(t_fenetre *d,
	int x, int y, double angle)
{
	char	*dest;

	(void)angle;
	if (d->inters == d->xi)
		dest = d->tmp_xpm + (y * d->size_xpm + x * (d->bpp_xpm / 8));
	else
		dest = d->tmp2_xpm + (y * d->size2_xpm + x * (d->bpp2_xpm / 8));
	return (*(unsigned int *)dest);
}

unsigned int	give_color_texture_down_right(t_fenetre *d,
	int x, int y, double angle)
{
	char	*dest;

	(void)angle;
	if (d->inters == d->xi)
		dest = d->tmp_xpm + (y * d->size_xpm + x * (d->bpp_xpm / 8));
	else
		dest = d->tmp3_xpm + (y * d->size3_xpm + x * (d->bpp3_xpm / 8));
	return (*(unsigned int *)dest);
}

unsigned int	give_color_texture_up_left(t_fenetre *d,
	int x, int y, double angle)
{
	char	*dest;

	(void)angle;
	if (d->inters == d->xi)
		dest = d->tmp4_xpm + (y * d->size4_xpm + x * (d->bpp4_xpm / 8));
	else
		dest = d->tmp3_xpm + (y * d->size3_xpm + x * (d->bpp3_xpm / 8));
	return (*(unsigned int *)dest);
}
