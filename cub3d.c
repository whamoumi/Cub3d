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

int	draww(t_fenetre *s)
{
	all_mouvement(s);
	draw_right_fov(s);
	draw_left_fov(s);
	mlx_put_image_to_window(s->id, s->win, s->img, 0, 0);
	mlx_destroy_image(s->id, s->img);
	s->img = mlx_new_image(s->id, s->longeur, s->largeur);
	return (0);
}

void	initialisation_of_image(t_fenetre *d)
{
	d->id = mlx_init();
	d->img = mlx_new_image(d->id, d->longeur, d->largeur);
	d->win = mlx_new_window(d->id, d->longeur, d->largeur, "cub3d");
	d->tmp = mlx_get_data_addr(d->img, &d->bpp, &d->size, &d->endian);
	d->tex = mlx_xpm_file_to_image(d->id, d->north_path, &d->height_xpm,
			&d->width_xpm);
	d->tex2 = mlx_xpm_file_to_image(d->id, d->south_path, &d->height2_xpm,
			&d->width2_xpm);
	d->tex3 = mlx_xpm_file_to_image(d->id, d->east_path, &d->height3_xpm,
			&d->width3_xpm);
	d->tex4 = mlx_xpm_file_to_image(d->id, d->west_path, &d->height4_xpm,
			&d->width4_xpm);
	d->tmp_xpm = mlx_get_data_addr(d->tex, &d->bpp_xpm, &d->size_xpm,
			&d->endian_xpm);
	d->tmp2_xpm = mlx_get_data_addr(d->tex2, &d->bpp2_xpm, &d->size2_xpm,
			&d->endian2_xpm);
	d->tmp3_xpm = mlx_get_data_addr(d->tex3, &d->bpp3_xpm, &d->size3_xpm,
			&d->endian3_xpm);
	d->tmp4_xpm = mlx_get_data_addr(d->tex4, &d->bpp4_xpm, &d->size4_xpm,
			&d->endian4_xpm);
	mlx_hook(d->win, 2, (1L << 0), key_press, d);
	mlx_hook(d->win, 17, 0, kill_the_windows, d);
	mlx_hook(d->win, 3, (1L << 1), key_release, d);
	mlx_loop_hook(d->id, draww, d);
	mlx_loop(d->id);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_mapp(t_fenetre *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			if (!(d->map[i][j] == '0' || d->map[i][j] == '1'
				|| d->map[i][j] == 'W' || d->map[i][j] == 'E'
				|| d->map[i][j] == 'N' || d->map[i][j] == 'S'
				|| d->map[i][j] == ' '))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_fenetre	d;
	t_parsing	data;

	if (argc == 2 && cub_file_check(argv[1]) == 1)
	{	
		if (premier_parsing(argv, &data) == 1
			&& deuxieme_parsing(&data, argv) == 1
			&& troisieme_parsing(&data, argv) == 1 && check_map(data.map) == 1)
		{
			initialisation_of_variables(&d, &data);
			if (d.playercount != 1)
				return (printf("MORE OR LESS THAN 1 PLAYER\n"));
			if (check_mapp(&d) == 0)
				return (printf("BAD CARACTERES IN MAP\n"));
			initialisation_of_image(&d);
		}
		else
			return (printf("ERROR OF PARSING IN FILE\n"));
	}
	else
	{
		if (cub_file_check(argv[1]) != 1)
			return (printf("NOT A .CUB FILE \n"));
		return (printf("BAD NUMBER OF ARGUMENT\n"));
	}
}
