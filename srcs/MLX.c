/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:26:53 by fgomez            #+#    #+#             */
/*   Updated: 2021/03/12 09:54:34 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_drawstartend(t_map *p)
{
	if (p->r.side == 0)
		p->r.walldist = ((double)p->r.mapx
				- p->r.posx + (1 - (double)p->r.stepx) / 2) / p->r.raydirx;
	else
		p->r.walldist = ((double)p->r.mapy
				- p->r.posy + (1 - (double)p->r.stepy) / 2) / p->r.raydiry;
	p->r.lineheight = (int)(p->screeny / p->r.walldist);
	p->r.drawstart = -p->r.lineheight / 2 + p->screeny / 2;
	if (p->r.drawstart < 0)
		p->r.drawstart = 0;
	p->r.drawend = p->r.lineheight / 2 + p->screeny / 2;
	if (p->r.drawend >= p->screeny || p->r.drawend < 0)
		p->r.drawend = p->screeny - 1;
	ft_color_column(p);
}

void	ft_incrementray(t_map *p)
{
	while (p->r.hit == 0)
	{
		if (p->r.sidedistx < p->r.sidedisty)
		{
			p->r.sidedistx += p->r.deltax;
			p->r.mapx += p->r.stepx;
			p->r.side = 0;
		}
		else
		{
			p->r.sidedisty += p->r.deltay;
			p->r.mapy += p->r.stepy;
			p->r.side = 1;
		}
		if (p->map[p->r.mapx][p->r.mapy] == '1')
			p->r.hit = 1;
	}
	ft_drawstartend(p);
}

void	ft_raycasting(t_map *p)
{
	if (p->r.raydirx < 0)
	{
		p->r.stepx = -1;
		p->r.sidedistx = (p->r.posx - p->r.mapx) * p->r.deltax;
	}
	else
	{
		p->r.stepx = 1;
		p->r.sidedistx = (p->r.mapx + 1.0 - p->r.posx) * p->r.deltax;
	}
	if (p->r.raydiry < 0)
	{
		p->r.stepy = -1;
		p->r.sidedisty = (p->r.posy - p->r.mapy) * p->r.deltay;
	}
	else
	{
		p->r.stepy = 1;
		p->r.sidedisty = (p->r.mapy + 1.0 - p->r.posy) * p->r.deltay;
	}
	ft_incrementray(p);
}

int	ft_run(t_map *p)
{
	p->r.x = 0;
	while (p->r.x < p->screenx)
	{
		ft_initialisation3(p);
		ft_raycasting(p);
		p->s.zbuffer[p->r.x] = p->r.walldist;
		p->r.x++;
	}
	ft_sprite(p);
	ft_drawminimap(p);
	mlx_put_image_to_window(p->d.mlx_ptr, p->d.win, p->d.img2, 0, 0);
	ft_move(p);
	return (0);
}

int	ft_mlx(t_map *p)
{
	ft_initialisation2(p);
	p->d.mlx_ptr = mlx_init();
	if (1920 < p->screenx)
		p->screenx = 1920;
	if (1420 < p->screeny)
		p->screeny = 1420;
	p->d.win = mlx_new_window(p->d.mlx_ptr, p->screenx, p->screeny, "cub3D");
	ft_get_texture(p);
	p->d.img2 = mlx_new_image(p->d.mlx_ptr, p->screenx, p->screeny);
	p->d.addr2 = mlx_get_data_addr(p->d.img2,
			&p->d.bpp, &p->d.ll, &p->d.endian);
	mlx_hook(p->d.win, 2, 1L << 0, ft_keypress, p);
	mlx_hook(p->d.win, 3, 1L << 1, ft_keyrelease, p);
	mlx_loop_hook(p->d.mlx_ptr, ft_run, p);
	mlx_loop(p->d.mlx_ptr);
	return (0);
}
