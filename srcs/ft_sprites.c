/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:41:09 by fgomez            #+#    #+#             */
/*   Updated: 2021/03/29 11:21:45 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_dist_order2(t_map *p)
{
	int	i;

	i = -1;
	while (++i < p->s.nbspr)
	{
		p->s.order[i] = i;
		p->s.dist[i] = ((p->r.posx - p->sxy[i].x)
				* (p->r.posx - p->sxy[i].x) + (p->r.posy
					- p->sxy[i].y) * (p->r.posy - p->sxy[i].y));
	}
}

void	ft_dist_order(t_map *p)
{
	int		i;
	int		j;
	double	tmp;

	ft_dist_order2(p);
	i = -1;
	while (++i < p->s.nbspr)
	{
		j = -1;
		while (++j < p->s.nbspr - 1)
		{
			if (p->s.dist[j] < p->s.dist[j + 1])
			{
				tmp = p->s.dist[j];
				p->s.dist[j] = p->s.dist[j + 1];
				p->s.dist[j + 1] = tmp;
				tmp = p->s.order[j];
				p->s.order[j] = p->s.order[j + 1];
				p->s.order[j + 1] = (int)tmp;
			}
		}
	}
}

void	ft_calculs(t_map *p, int i)
{
	p->s.spritex = p->sxy[p->s.order[i]].x - p->r.posx;
	p->s.spritey = p->sxy[p->s.order[i]].y - p->r.posy;
	p->s.invdet = 1.0 / (p->r.planx * p->r.diry
			- p->r.dirx * p->r.plany);
	p->s.transformx = p->s.invdet * (p->r.diry
			* p->s.spritex - p->r.dirx * p->s.spritey);
	p->s.transformy = p->s.invdet * (-p->r.plany
			* p->s.spritex + p->r.planx * p->s.spritey);
	p->s.spritescreenx = (int)((p->screenx / 2) * (1 + p->s.transformx
				/ p->s.transformy));
	p->s.spriteheight = abs((int)(p->screeny / (p->s.transformy)));
	p->s.drawstarty = -p->s.spriteheight / 2 + p->screeny / 2;
	if (p->s.drawstarty < 0)
		p->s.drawstarty = 0;
	p->s.drawendy = p->s.spriteheight / 2 + p->screeny / 2;
	if (p->s.drawendy >= p->screeny)
		p->s.drawendy = p->screeny;
	p->s.spritewidth = abs((int)(p->screeny / (p->s.transformy)));
	p->s.drawstartx = -p->s.spritewidth / 2 + p->s.spritescreenx;
	if (p->s.drawstartx < 0)
		p->s.drawstartx = 0;
	p->s.drawendx = p->s.spritewidth / 2 + p->s.spritescreenx;
	if (p->s.drawendx >= p->screenx)
		p->s.drawendx = p->screenx;
}

void	ft_draw_spr(t_map *p, int y, int texx, int stripe)
{
	int		d;
	int		texy;

	while (y < p->s.drawendy)
	{
		d = (y) * 256 - p->screeny * 128 + p->s.spriteheight * 128;
		texy = ((d * p->texture[4].height) / p->s.spriteheight) / 256;
		if (p->texture[4].addr2[texy * p->texture[4].ll + texx
				* (p->texture[4].bpp / 8)] != 0)
			ft_draw_pixel(p, stripe, y, ft_sprite_color(p, texx, texy));
		y++;
	}
}

void	ft_sprite(t_map *p)
{
	int	i;
	int	y;
	int	stripe;
	int	texx;

	i = -1;
	ft_dist_order(p);
	while (++i < p->s.nbspr)
	{
		ft_calculs(p, i);
		stripe = p->s.drawstartx;
		while (stripe < p->s.drawendx)
		{
			texx = (int)(256 * (stripe - (-p->s.spritewidth
							/ 2 + p->s.spritescreenx)) * p->texture[4].width
					/ p->s.spritewidth) / 256;
			if (p->s.transformy > 0 && stripe >= 0 && stripe < p->screenx
				&& p->s.transformy < p->s.zbuffer[stripe])
			{
				y = p->s.drawstarty;
				ft_draw_spr(p, y, texx, stripe);
			}
			stripe++;
		}
	}
}
