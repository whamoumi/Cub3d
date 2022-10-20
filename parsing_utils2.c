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

int	check_path_south(char *str, t_parsing *data)
{
	char	**first_tab;

	first_tab = ft_split(str, ' ');
	if (size_of_tab(first_tab) != 2)
		return (0);
	else
	{
		if (open(first_tab[1], O_RDONLY) == -1)
			return (free_tab(first_tab[0], first_tab[1], first_tab));
		else
		{
			if (!(first_tab[1][0] == '.' && first_tab[1][1] == '/'))
				return (free_tab(first_tab[0], first_tab[1], first_tab));
			data->south_texture = ft_strdup(first_tab[1]);
			free(first_tab[0]);
			free(first_tab[1]);
			free(first_tab);
			return (1);
		}	
	}
}

int	check_path_east(char *str, t_parsing *data)
{
	char	**first_tab;

	first_tab = ft_split(str, ' ');
	if (size_of_tab(first_tab) != 2)
		return (0);
	else
	{
		if (open(first_tab[1], O_RDONLY) == -1)
			return (free_tab(first_tab[0], first_tab[1], first_tab));
		else
		{
			if (!(first_tab[1][0] == '.' && first_tab[1][1] == '/'))
				return (free_tab(first_tab[0], first_tab[1], first_tab));
			data->east_texture = ft_strdup(first_tab[1]);
			free(first_tab[0]);
			free(first_tab[1]);
			free(first_tab);
			return (1);
		}	
	}
}

int	check_path_west(char *str, t_parsing *data)
{
	char	**first_tab;

	first_tab = ft_split(str, ' ');
	if (size_of_tab(first_tab) != 2)
		return (0);
	else
	{
		if (open(first_tab[1], O_RDONLY) == -1)
			return (free_tab(first_tab[0], first_tab[1], first_tab));
		else
		{
			if (!(first_tab[1][0] == '.' && first_tab[1][1] == '/'))
				return (free_tab(first_tab[0], first_tab[1], first_tab));
			data->west_texture = ft_strdup(first_tab[1]);
			free(first_tab[0]);
			free(first_tab[1]);
			free(first_tab);
			return (1);
		}	
	}
}

int	check_path(char *str, t_parsing *data)
{
	int	check;

	check = 0;
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		check += check_path_north(str, data);
	else if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		check += check_path_south(str, data);
	else if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		check += check_path_west(str, data);
	else if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		check += check_path_east(str, data);
	else if (str[0] == 'F' && str[1] == ' ')
		check += check_path_floor(str, data);
	else if (str[0] == 'C' && str[1] == ' ')
		check += check_path_ceil(str, data);
	else if (str[0] == '\0')
		check += 0;
	else
		check = -100;
	return (check);
}

int	check_zero(char **map, int i, int j)
{
	if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E'
		&& map[i][j] != 'W' && map[i][j] != 'S' && map[i][j] != 'N' )
		return (0);
	else
		return (1);
}
