/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:33:01 by fgomez            #+#    #+#             */
/*   Updated: 2021/03/31 11:29:10 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_exit(t_map *p)
{
	if (p->d.img2)
		mlx_destroy_image(p->d.mlx_ptr, p->d.img2);
	if (p->texture[0].img2)
		mlx_destroy_image(p->d.mlx_ptr, p->texture[0].img2);
	if (p->texture[1].img2)
		mlx_destroy_image(p->d.mlx_ptr, p->texture[1].img2);
	if (p->texture[2].img2)
		mlx_destroy_image(p->d.mlx_ptr, p->texture[2].img2);
	if (p->texture[3].img2)
		mlx_destroy_image(p->d.mlx_ptr, p->texture[3].img2);
	if (p->texture[4].img2)
		mlx_destroy_image(p->d.mlx_ptr, p->texture[4].img2);
	if (p->d.win)
		mlx_destroy_window(p->d.mlx_ptr, p->d.win);
	exit(0);
}

void	ft_error2(t_map *p)
{
	if (p->map)
		free(p->map);
	if (p->s.order)
		free(p->s.order);
	if (p->s.dist)
		free(p->s.dist);
	if (p->sxy)
		free(p->sxy);
	if (p->s.zbuffer)
		free(p->s.zbuffer);
	ft_exit(p);
}

int	ft_g_error(char *str, t_map *p)
{
	int	i;

	i = -1;
	ft_putstr(str);
	if (p->no)
		free(p->no);
	if (p->so)
		free(p->so);
	if (p->we)
		free(p->we);
	if (p->ea)
		free(p->ea);
	if (p->sp)
		free(p->sp);
	if (p->map)
	{
		while (++i < p->nblignes)
			free(p->map[i]);
	}
	ft_error2(p);
	return (0);
}
