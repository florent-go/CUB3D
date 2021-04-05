/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:07:37 by fgomez            #+#    #+#             */
/*   Updated: 2021/03/30 10:55:01 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_drawsquare(t_map *p, int i, int j, int color)
{
	int	x;
	int	y;
	int	convertsize;

	y = j;
	convertsize = p->screenx / 6 / p->sizelignes;
	while (y < j + convertsize)
	{
		x = i;
		while (x < i + convertsize)
		{
			ft_draw_pixel(p, x, y, color);
			x++;
		}
		y++;
	}
}

void	ft_move_player(t_map *p, int convertsize)
{
	ft_drawsquare(p, (int)p->r.posy * convertsize,
		(int)p->r.posx * convertsize, 0x0000FF00);
}

void	ft_drawminimap(t_map *p)
{
	int	i;
	int	j;
	int	convertsize;

	j = 0;
	i = 0;
	convertsize = p->screenx / 6 / p->sizelignes;
	while (j < p->nblignes)
	{
		i = 0;
		while (p->map[j][i] != '\0')
		{
			if (p->map[j][i] == '2')
				ft_drawsquare(p, i * convertsize, j * convertsize, 0x00FF0000);
			if (p->map[j][i] == '1')
				ft_drawsquare(p, i * convertsize, j * convertsize, 0x00000000);
			if (p->map[j][i] == '0')
				ft_drawsquare(p, i * convertsize, j * convertsize, 0x00FFFFFF);
			i++;
		}
		j++;
	}
	ft_move_player(p, convertsize);
}
