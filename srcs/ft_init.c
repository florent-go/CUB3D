/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:43:11 by fgomez            #+#    #+#             */
/*   Updated: 2021/03/31 12:57:52 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_initialisation(t_map *p)
{
	p->no = NULL;
	p->so = NULL;
	p->we = NULL;
	p->ea = NULL;
	p->sp = NULL;
	p->nblignes = 0;
	p->sizelignes = 0;
	p->screenx = 0;
	p->screeny = 0;
	p->dx = 0;
	p->dy = 0;
	p->depart = 'x';
	p->ro = -1;
	p->bl = -1;
	p->gr = -1;
	p->f = -1;
	p->c = -1;
	p->d.win = NULL;
	p->d.img2 = NULL;
	p->texture[0].img2 = NULL;
	p->texture[1].img2 = NULL;
	p->texture[2].img2 = NULL;
	p->texture[3].img2 = NULL;
	p->texture[4].img2 = NULL;
}

void	ft_init_dir(t_map *p)
{
	if (p->depart == 'N')
		p->r.dirx = -1;
	if (p->depart == 'S')
		p->r.dirx = 1;
	if (p->depart == 'E')
		p->r.diry = 1;
	if (p->depart == 'W')
		p->r.diry = -1;
	if (p->depart == 'N')
		p->r.plany = 0.66;
	if (p->depart == 'S')
		p->r.plany = -0.66;
	if (p->depart == 'E')
		p->r.planx = 0.66;
	if (p->depart == 'W')
		p->r.planx = -0.66;
}

void	ft_init_more3(t_map *p)
{
	if (p->r.raydiry == 0)
		p->r.deltax = 0;
	else if (p->r.raydirx == 0)
		p->r.deltax = 1;
	else
		p->r.deltax = sqrt(1 + (p->r.raydiry * p->r.raydiry)
				/ (p->r.raydirx * p->r.raydirx));
	if (p->r.raydirx == 0)
		p->r.deltay = 0;
	else if (p->r.raydiry == 0)
		p->r.deltay = 1;
	else
		p->r.deltay = sqrt(1 + (p->r.raydirx * p->r.raydirx)
				/ (p->r.raydiry * p->r.raydiry));
}

void	ft_initialisation2(t_map *p)
{
	p->s.zbuffer = (double *)malloc(sizeof(double) * p->screenx);
	if (!(p->s.zbuffer))
		exit(0);
	p->forward = 0;
	p->backward = 0;
	p->left = 0;
	p->right = 0;
	p->rotate_right = 0;
	p->rotate_left = 0;
	p->r.posx = (double)p->dx + 0.5;
	p->r.posy = (double)p->dy + 0.5;
	ft_init_dir(p);
}

void	ft_initialisation3(t_map *p)
{
	p->r.hit = 0;
	p->r.walldist = 0;
	p->r.camera = 2 * p->r.x / (double)p->screenx - 1;
	p->r.raydirx = p->r.dirx + p->r.planx * p->r.camera;
	p->r.raydiry = p->r.diry + p->r.plany * p->r.camera;
	p->r.mapx = (int)p->r.posx;
	p->r.mapy = (int)p->r.posy;
	p->r.movespeed = 0.1;
	p->r.rotspeed = 0.033 * 3;
	ft_init_more3(p);
}
