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

double	distance_line_intersectionn(t_fenetre *s, double angle)
{
	double	r;

	give_line_coorddd(s, angle);
	s->inters = s->xi;
	r = s->disthhh;
	return (r);
}

double	distance_vertical_intersection(t_fenetre *s, double angle)
{
	double	r;

	give_vert_coord(s, angle);
	s->inters = s->yi;
	r = s->distv;
	return (r);
}

double	distance_vertical_intersectionn(t_fenetre *s, double angle)
{
	double	r;

	give_vert_coordd(s, angle);
	s->inters = s->yi;
	r = s->distvv;
	return (r);
}

double	distance_vertical_intersectionnn(t_fenetre *s, double angle)
{
	double	r;

	give_vert_coord(s, angle);
	s->inters = s->yi;
	r = s->distv;
	return (r);
}

double	ray_draw(t_fenetre *s, double angle)
{
	double	r;

	angle = check_angle(angle);
	if (angle <= 0)
		distance_vertical_intersection(s, angle);
	if (angle == M_PI / 2)
		r = distance_line_intersectionn(s, angle);
	if (angle == M_PI)
		r = distance_vertical_intersectionn(s, angle);
	if (angle == 3 * (M_PI / 2))
		r = distance_line_intersectionn(s, angle);
	if (angle > 2 * M_PI)
		distance_vertical_intersection(s, angle);
	if (angle > 0 && angle < (M_PI / 2))
		r = distance_down_right(s, angle);
	if (angle > (M_PI / 2) && angle < M_PI)
		r = distance_down_left(s, angle);
	if (angle > M_PI && angle < (3 * M_PI / 2))
		r = distance_up_left(s, angle);
	if (angle > (3 * M_PI / 2) && angle < (2 * M_PI))
		r = distance_up_right(s, angle);
	return (r);
}
