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

void	parsing_utils(t_parsing *data, char **sec_tab)
{
	data->red_floor = ft_atoi(sec_tab[0]);
	data->green_floor = ft_atoi(sec_tab[1]);
	data->blue_floor = ft_atoi(sec_tab[2]);
	free_ta(sec_tab[0], sec_tab[1], sec_tab[2], sec_tab);
}

void	parsing_utils2(t_parsing *data, char **sec_tab)
{
	data->red_ceil = ft_atoi(sec_tab[0]);
	data->green_ceil = ft_atoi(sec_tab[1]);
	data->blue_ceil = ft_atoi(sec_tab[2]);
	free_ta(sec_tab[0], sec_tab[1], sec_tab[2], sec_tab);
}

void	give_len_of_line(t_parsing *data)
{
	data->taille = ft_strlen(data->line);
	free(data->line);
	if (data->taille > data->taille_ligne)
		data->taille_ligne = data->taille;
	data->taille_tab++;
}

int	troisieme_parsingg(t_parsing *data, int i, int y)
{
	i = 0;
	data->map[i] = malloc(sizeof(char) * data->taille_ligne + 1);
	y = -1;
	while (++y < (int)data->taille_ligne)
		data->map[i][y] = ' ';
	data->map[i][y] = '\0';
	y = -1;
	while (data->line[++y])
		data->map[i][y] = data->line[y];
	free(data->line);
	i++;
	while (get_next_line(data->fd2, &data->line) == 1)
	{
		data->map[i] = malloc(sizeof(char) * data->taille_ligne + 1);
		y = -1;
		while (++y < (int)data->taille_ligne)
			data->map[i][y] = ' ';
		data->map[i][y] = '\0';
		y = -1;
		while (data->line[++y])
			data->map[i][y] = data->line[y];
		free(data->line);
		i++;
	}
	return (i);
}

int	is_all_num(char **sec_tab)
{
	if (is_num(sec_tab[0]) == 0 || is_num(sec_tab[1]) == 0
		|| is_num(sec_tab[2]) == 0)
		return (0);
	return (1);
}
