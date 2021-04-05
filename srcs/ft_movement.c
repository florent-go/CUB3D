/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 09:22:36 by fgomez            #+#    #+#             */
/*   Updated: 2021/03/31 11:14:34 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_forward_back(t_map *p)
{
	if (p->forward == 1)
	{
		if (p->map[(int)(p->r.posx + (p->r.dirx
					* p->r.movespeed * 2))][(int)p->r.posy] == '0')
			p->r.posx += p->r.dirx * p->r.movespeed;
		if (p->map[(int)(p->r.posx)][(int)(p->r.posy
			+ (p->r.diry * p->r.movespeed * 2))] == '0')
			p->r.posy += p->r.diry * p->r.movespeed;
	}
	if (p->backward == 1)
	{
		if (p->map[(int)(p->r.posx - (p->r.dirx
					* p->r.movespeed * 2))][(int)(p->r.posy)] == '0')
			p->r.posx -= p->r.dirx * p->r.movespeed;
		if (p->map[(int)(p->r.posx)][(int)(p->r.posy
			- (p->r.diry * p->r.movespeed * 2))] == '0')
			p->r.posy -= p->r.diry * p->r.movespeed;
	}
}

void	ft_left_right(t_map *p)
{
	if (p->right == 1)
	{
		if (p->map[(int)(p->r.posx + p->r.diry
				* (p->r.movespeed * 2))][(int)p->r.posy] == '0')
			p->r.posx += p->r.diry * p->r.movespeed;
		if (p->map[(int)p->r.posx][(int)(p->r.posy - p->r.dirx
			* (p->r.movespeed * 2))] == '0')
			p->r.posy -= p->r.dirx * p->r.movespeed;
	}
	if (p->left == 1)
	{
		if (p->map[(int)(p->r.posx - p->r.diry
				* (p->r.movespeed * 2))][(int)p->r.posy] == '0')
			p->r.posx -= p->r.diry * p->r.movespeed;
		if (p->map[(int)p->r.posx][(int)(p->r.posy
			+ p->r.dirx * (p->r.movespeed * 2))] == '0')
			p->r.posy += p->r.dirx * p->r.movespeed;
	}
}

void	ft_rotate_left(t_map *p, double olddirx)
{
	double	oldplanex;

	if (p->rotate_left == 1)
	{
		olddirx = p->r.dirx;
		oldplanex = p->r.planx;
		p->r.dirx = p->r.dirx * cos(p->r.rotspeed / 2)
			- p->r.diry * sin(p->r.rotspeed / 2);
		p->r.diry = olddirx * sin(p->r.rotspeed / 2)
			+ p->r.diry * cos(p->r.rotspeed / 2);
		p->r.planx = p->r.planx * cos(p->r.rotspeed / 2)
			- p->r.plany * sin(p->r.rotspeed / 2);
		p->r.plany = oldplanex * sin(p->r.rotspeed / 2)
			+ p->r.plany * cos(p->r.rotspeed / 2);
	}
}

void	ft_rotate_right_left(t_map *p)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = p->r.planx;
	olddirx = p->r.dirx;
	if (p->rotate_right == 1)
	{
		p->r.dirx = p->r.dirx * cos(-p->r.rotspeed / 2)
			- p->r.diry * sin(-p->r.rotspeed / 2);
		p->r.diry = olddirx * sin(-p->r.rotspeed / 2)
			+ p->r.diry * cos(-p->r.rotspeed / 2);
		p->r.planx = p->r.planx * cos(-p->r.rotspeed / 2)
			- p->r.plany * sin(-p->r.rotspeed / 2);
		p->r.plany = oldplanx * sin(-p->r.rotspeed / 2)
			+ p->r.plany * cos(-p->r.rotspeed / 2);
	}
	ft_rotate_left(p, olddirx);
}

int	ft_move(t_map *params)
{
	ft_forward_back(params);
	ft_left_right(params);
	ft_rotate_right_left(params);
	return (0);
}
