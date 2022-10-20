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

int	check_element(char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		return (1);
	else if (str[0] == 'S' && str[1] == 'O')
		return (1);
	else if (str[0] == 'W' && str[1] == 'E')
		return (1);
	else if (str[0] == 'E' && str[1] == 'A')
		return (1);
	else if (str[0] == 'F')
		return (1);
	else if (str[0] == 'C')
		return (1);
	else
		return (10);
}

int	size_of_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_path_floor(char *str, t_parsing *data)
{
	char	**first_tab;
	char	**sec_tab;

	first_tab = ft_split(str, ' ');
	sec_tab = ft_split(first_tab[1], ',');
	if (size_of_tab(first_tab) != 2)
		return (0);
	else
	{
		free_tab(first_tab[0], first_tab[1], first_tab);
		if (size_of_tab(sec_tab) != 3)
			return (free_ta(sec_tab[0], sec_tab[1], sec_tab[2], sec_tab));
		else
		{
			if (((ft_atoi(sec_tab[0]) >= 0) && (ft_atoi(sec_tab[0]) <= 255))
				&& ((ft_atoi(sec_tab[1]) >= 0) && (ft_atoi(sec_tab[1]) <= 255))
				&& ((ft_atoi(sec_tab[2]) >= 0) && (ft_atoi(sec_tab[2]) <= 255))
				&& is_all_num(sec_tab) == 1)
				parsing_utils(data, sec_tab);
			else
				return (free_ta(sec_tab[0], sec_tab[1], sec_tab[2], sec_tab));
		}
	}
	return (1);
}

int	check_path_ceil(char *str, t_parsing *data)
{
	char	**first_tab;
	char	**sec_tab;

	first_tab = ft_split(str, ' ');
	sec_tab = ft_split(first_tab[1], ',');
	if (size_of_tab(first_tab) != 2)
		return (0);
	else
	{
		free_tab(first_tab[0], first_tab[1], first_tab);
		if (size_of_tab(sec_tab) != 3)
			return (free_ta(sec_tab[0], sec_tab[1], sec_tab[2], sec_tab));
		else
		{
			if (((ft_atoi(sec_tab[0]) >= 0) && (ft_atoi(sec_tab[0]) <= 255))
				&& ((ft_atoi(sec_tab[1]) >= 0) && (ft_atoi(sec_tab[1]) <= 255))
				&& ((ft_atoi(sec_tab[2]) >= 0) && (ft_atoi(sec_tab[2]) <= 255))
				&& is_all_num(sec_tab) == 1)
				parsing_utils2(data, sec_tab);
			else
				return (free_ta(sec_tab[0], sec_tab[1], sec_tab[2], sec_tab));
		}
	}
	return (1);
}

int	check_path_north(char *str, t_parsing *data)
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
			data->north_texture = ft_strdup(first_tab[1]);
			free(first_tab[0]);
			free(first_tab[1]);
			free(first_tab);
			return (1);
		}	
	}
}
