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

int	check_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
			{
				if (check_zero(map, i, j + 1) == 0
					|| check_zero(map, i, j - 1) == 0
					|| check_zero(map, i + 1, j) == 0
					|| check_zero(map, i - 1, j) == 0
					|| check_zero(map, i + 1, j - 1) == 0
					|| check_zero(map, i + 1, j + 1) == 0
					|| check_zero(map, i - 1, j - 1) == 0
					|| check_zero(map, i - 1, j + 1) == 0)
					return (0);
			}
		}
	}
	return (1);
}

int	check_number_of_element(t_parsing *data, char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		data->no++;
	else if (str[0] == 'S' && str[1] == 'O')
		data->so++;
	else if (str[0] == 'W' && str[1] == 'E')
		data->we++;
	else if (str[0] == 'E' && str[1] == 'A')
		data->ea++;
	else if (str[0] == 'F')
		data->f++;
	else if (str[0] == 'C')
		data->c++;
	if (data->no == 1 && data->so == 1 && data->we == 1
		&& data->ea == 1 && data->f == 1 && data->c == 1)
		return (1);
	return (0);
}

void	initialisation_variables(t_parsing *data)
{
	data->counter = 0;
	data->premiere_passe = 0;
	data->no = 0;
	data->so = 0;
	data->we = 0;
	data->ea = 0;
	data->f = 0;
	data->c = 0;
	data->check = 0;
	data->taille_tab = 0;
	data->taille_ligne = 0;
	data->taille = 0;
}

int	premier_parsing(char **argv, t_parsing *data)
{
	data->fd = open(argv[1], O_RDONLY);
	initialisation_variables(data);
	while (get_next_line(data->fd, &data->line) == 1)
	{
		if (data->line[0] == '\0')
			;
		else
		{
			check_number_of_element(data, data->line);
			data->counter += check_element(data->line);
		}
		free(data->line);
		data->premiere_passe++;
		if (data->counter == 6 && check_number_of_element(data, "") == 1)
			break ;
	}
	close(data->fd);
	if (data->counter != 6 && check_number_of_element(data, "") != 1)
		return (0);
	return (1);
}

int	deuxieme_parsing(t_parsing *data, char **argv)
{
	unsigned int	i;

	i = -1;
	data->fd1 = open(argv[1], O_RDONLY);
	while (get_next_line(data->fd1, &data->line) == 1
		&& ++i < data->premiere_passe)
	{
		data->check += check_path(data->line, data);
		free(data->line);
	}
	if (data->check == 6)
	{
		data->taille = ft_strlen(data->line);
		free(data->line);
		data->taille_tab++;
		while (get_next_line(data->fd1, &data->line) == 1)
			give_len_of_line(data);
		free(data->line);
		close(data->fd1);
		return (1);
	}
	return (0);
}
