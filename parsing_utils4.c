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

int	troisieme_parsing(t_parsing *data, char **argv)
{
	int	i;
	int	y;

	i = 0;
	y = -1;
	data->fd2 = open(argv[1], O_RDONLY);
	data->map = malloc(sizeof(char *) * data->taille_tab + 1);
	if (!data->map)
		return (0);
	while (get_next_line(data->fd2, &data->line) == 1
		&& i < (int)data->premiere_passe)
	{
		free(data->line);
		i++;
	}
	i = troisieme_parsingg(data, i, y);
	free(data->line);
	data->line = NULL;
	data->map[i] = NULL;
	return (1);
}

void	give_position_of_player(t_fenetre *d)
{
	d->jj = -1;
	while (d->map[++d->jj])
	{
		d->ii = -1;
		while (++d->ii < d->col)
		{
			if (d->map[d->jj][d->ii] == 'W' || d->map[d->jj][d->ii] == 'S'
				|| d->map[d->jj][d->ii] == 'E' || d->map[d->jj][d->ii] == 'N')
			{
				d->px = (d->ii * 64);
				d->py = (d->jj * 64);
				d->playercount++;
				if (d->map[d->jj][d->ii] == 'N')
					d->pa = 3 * M_PI / 2;
				if (d->map[d->jj][d->ii] == 'E')
					d->pa = 0 + (M_PI / 180);
				if (d->map[d->jj][d->ii] == 'W')
					d->pa = M_PI;
				if (d->map[d->jj][d->ii] == 'S')
					d->pa = (M_PI / 2) + (M_PI / 180);
			}
		}
	}
}

void	initialisation_of_variabless(t_fenetre *d, t_parsing *data)
{
	d->jj = -1;
	d->ii = -1;
	d->modeh = 0;
	d->modeb = 0;
	d->moded = 0;
	d->modeg = 0;
	d->modeesc = 0;
	d->modefd = 0;
	d->modefg = 0;
	d->playercount = 0;
	d->ligne = data->taille_tab;
	d->col = data->taille_ligne;
	d->r_c = data->red_ceil;
	d->g_c = data->green_ceil;
	d->b_c = data->blue_ceil;
	d->r_f = data->red_floor;
}

void	initialisation_of_variables(t_fenetre *d, t_parsing *data)
{
	initialisation_of_variabless(d, data);
	d->g_f = data->green_floor;
	d->b_f = data->blue_floor;
	d->north_path = data->north_texture;
	d->south_path = data->south_texture;
	d->east_path = data->east_texture;
	d->west_path = data->west_texture;
	d->map = data->map;
	give_position_of_player(d);
	d->longeur = 1200;
	d->largeur = 600;
	d->pdy = sin(d->pa);
	d->pdx = cos(d->pa);
	d->fov_angle = (M_PI / 3) / (d->longeur);
	d->projection = (d->longeur / 2) / (tan(M_PI / 6));
}

int	cub_file_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (ft_strlen(str) <= 4)
		return (0);
	if (str[i] == 'b' && str[i - 1] == 'u'
		&& str[i - 2] == 'c' && str[i - 3] == '.')
		return (1);
	else
		return (0);
}
