/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:58:19 by fgomez            #+#    #+#             */
/*   Updated: 2021/03/31 11:16:29 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_pixel(t_map *p, int x, int y, int color)
{
	char	*dst;

	dst = p->d.addr2 + (y * p->d.ll + x * (p->d.bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_sprite_color(t_map *p, int x, int y)
{
	char	*dst;

	dst = &p->texture[4].addr2[y * p->texture[4].ll + x
		* (p->texture[4].bpp / 8)];
	return (*(unsigned int *)dst);
}

unsigned int	ft_text_color(t_map *p)
{
	char	*dst;

	dst = &p->texture[p->t.texdir].addr2[p->t.texy
		* p->texture[p->t.texdir].ll + p->t.texx
		* (p->texture[p->t.texdir].bpp / 8)];
	return (*(unsigned int *)dst);
}

void	ft_draw_texture(t_map *p, int x, int y)
{
	y = p->r.drawstart - 1;
	ft_init_texture(p);
	p->t.step = 1.0 * p->texture[0].height / p->r.lineheight;
	p->t.texx = (int)(p->t.wallx * (double)p->texture[p->t.texdir].width);
	if (p->r.side == 0 && p->r.raydirx > 0)
		p->t.texx = p->texture[p->t.texdir].width - p->t.texx - 1;
	if (p->r.side == 1 && p->r.raydiry < 0)
		p->t.texx = p->texture[p->t.texdir].width - p->t.texx - 1;
	p->t.texpos = (p->r.drawstart - p->screeny / 2
			+ p->r.lineheight / 2) * p->t.step;
	while (++y <= p->r.drawend)
	{
		p->t.texy = (int)p->t.texpos & (p->texture[p->t.texdir].height - 1);
		p->t.texpos += p->t.step;
		if (y < p->screeny && x < p->screenx)
			ft_draw_pixel(p, x, y, ft_text_color(p));
	}
}

int	ft_color_column(t_map *p)
{
	int	j;
	int	i;

	j = -1;
	p->r.drawend = p->screeny - p->r.drawstart;
	i = p->r.drawend;
	while (++j < p->r.drawstart)
		ft_draw_pixel(p, p->r.x, j, p->c);
	if (j <= p->r.drawend)
		ft_draw_texture(p, p->r.x, j);
	j = i;
	while (++j < p->screeny)
		ft_draw_pixel(p, p->r.x, j, p->f);
	return (0);
}
