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

double	distance_up_right(t_fenetre *s, double angle)
{
	double	r;

	give_vert_coordddd(s, angle);
	give_line_coordddd(s, angle);
	if (s->disthhhh <= s->distvvvv)
	{
		r = s->disthhhh;
		s->inters = s->xi;
	}
	else
	{
		r = s->distvvvv;
		s->inters = s->yi;
	}
	return (r);
}

double	distance_up_left(t_fenetre *s, double angle)
{
	double	r;

	give_vert_coorddd(s, angle);
	give_line_coorddd(s, angle);
	if (s->disthhh <= s->distvvv)
	{
		r = s->disthhh;
		s->inters = s->xi;
	}
	else
	{
		r = s->distvvv;
		s->inters = s->yi;
	}
	return (r);
}

double	distance_down_left(t_fenetre *s, double angle)
{
	double	r;

	give_vert_coordd(s, angle);
	give_line_coordd(s, angle);
	if (s->disthh <= s->distvv)
	{
		r = s->disthh;
		s->inters = s->xi;
	}
	else
	{
		r = s->distvv;
		s->inters = s->yi;
	}
	return (r);
}

double	distance_down_right(t_fenetre *s, double angle)
{
	double	r;

	give_vert_coord(s, angle);
	give_line_coord(s, angle);
	if (s->disth <= s->distv)
	{
		r = s->disth;
		s->inters = s->xi;
	}
	else
	{
		r = s->distv;
		s->inters = s->yi;
	}
	return (r);
}

double	distance_line_intersection(t_fenetre *s, double angle)
{
	double	r;

	give_line_coord(s, angle);
	s->inters = s->xi;
	r = s->disth;
	return (r);
}
