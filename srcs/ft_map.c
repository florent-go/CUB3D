/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 09:50:48 by fgomez            #+#    #+#             */
/*   Updated: 2021/04/01 11:37:27 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_murs(t_map *p)
{
	int	i;

	i = 0;
	while (i < p->nblignes)
	{
		if (p->map[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < p->nblignes)
	{
		if (p->map[i][p->sizelignes - 1] != '1')
			return (1);
		i++;
	}
	if (ft_murs_util(p->map[0]) == 1)
		return (1);
	if (ft_murs_util(p->map[p->nblignes - 1]) == 1)
		return (1);
	return (0);
}

int	ft_copy_map(char *str, t_map *map)
{
	static int	i = 0;
	int			j;

	j = 0;
	map->map[i] = malloc(sizeof(char) * map->sizelignes + 1);
	if (!(map->map[i]))
		return (0);
	while (str[j] != '\0')
	{
		if (ft_depart(str[j], map, i, j) == 1)
			map->map[i][j] = '0';
		else if (str[j] == ' ')
			map->map[i][j] = '1';
		else
			map->map[i][j] = str[j];
		j++;
	}
	while (j <= (map->sizelignes - 1))
	{
		map->map[i][j] = '1';
		j++;
	}
	map->map[i][j] = '\0';
	i++;
	return (0);
}

int	ft_is_map(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charinstr(str, '1') == 1 || ft_charinstr(str, '0') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1'
				&& str[i] != '2' && str[i] != 'N' && str[i] != 'S'
				&& str[i] != 'E' && str[i] != 'W' && str[i] != '\n'
				&& str[i] != '\t')
			{
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_map(char *str, t_map *map)
{
	int			i;
	static int	snblines = 0;
	static int	ssizeline = 0;

	i = 0;
	if (ft_is_map(str) == 1)
	{
		i = ft_strlen(str);
		if (i > ssizeline)
			ssizeline = i;
		snblines = snblines + 1;
	}
	map->nblignes = snblines;
	map->sizelignes = ssizeline;
}
