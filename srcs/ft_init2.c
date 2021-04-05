/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:58:11 by fgomez            #+#    #+#             */
/*   Updated: 2021/03/31 11:52:11 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_sprite(t_map *p)
{
	int	i;
	int	j;

	i = -1;
	p->s.nbspr = 0;
	while (++i < p->nblignes)
	{
		j = -1;
		while (++j < p->sizelignes)
		{
			if (p->map[i][j] == '2')
				p->s.nbspr += 1;
		}
	}
	p->sxy = (t_sprxy *)malloc(sizeof(t_sprxy) * p->s.nbspr);
	if (!(p->sxy))
		ft_g_error("Error\nMalloc sxy*", p);
	p->s.order = (int *)malloc(sizeof(int) * p->s.nbspr);
	if (!(p->s.order))
		ft_g_error("Error\nMalloc s.order*", p);
	p->s.dist = (double *)malloc(sizeof(double) * p->s.nbspr);
	if (!(p->s.dist))
		ft_g_error("Error\nMalloc s.dist*", p);
	ft_init_sprite2(p, 0, 0, 0);
}

void	ft_init_sprite2(t_map *p, int i, int j, int v)
{
	i = i - 1;
	while (++i < p->nblignes)
	{
		j = -1;
		while (++j < p->sizelignes)
		{
			if (p->map[i][j] == '2')
			{
				p->sxy[v].x = (double)i + 0.5;
				p->sxy[v].y = (double)j + 0.5;
				v++;
			}
		}
	}
}
