/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 11:07:04 by fgomez            #+#    #+#             */
/*   Updated: 2021/03/31 12:39:03 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_get_texture_adress(t_map *p)
{
	p->texture[0].addr2 = mlx_get_data_addr(p->texture[0].img2,
			&p->texture[0].bpp, &p->texture[0].ll, &p->texture[0].endian);
	p->texture[1].addr2 = mlx_get_data_addr(p->texture[1].img2,
			&p->texture[1].bpp, &p->texture[1].ll, &p->texture[1].endian);
	p->texture[2].addr2 = mlx_get_data_addr(p->texture[2].img2,
			&p->texture[2].bpp, &p->texture[2].ll, &p->texture[2].endian);
	p->texture[3].addr2 = mlx_get_data_addr(p->texture[3].img2,
			&p->texture[3].bpp, &p->texture[3].ll, &p->texture[3].endian);
	p->texture[4].addr2 = mlx_get_data_addr(p->texture[4].img2,
			&p->texture[4].bpp, &p->texture[4].ll, &p->texture[4].endian);
}

void	ft_get_texture(t_map *p)
{
	p->texture[0].img2 = mlx_xpm_file_to_image(p->d.mlx_ptr, p->no,
			&(p->texture[0].width), &(p->texture[0].height));
	if (!(p->texture[0].img2))
		ft_g_error("Error\nTexture SO", p);
	p->texture[1].img2 = mlx_xpm_file_to_image(p->d.mlx_ptr, p->so,
			&(p->texture[1].width), &(p->texture[1].height));
	if (!(p->texture[1].img2))
		ft_g_error("Error\nTexture NO", p);
	p->texture[2].img2 = mlx_xpm_file_to_image(p->d.mlx_ptr, p->we,
			&(p->texture[2].width), &(p->texture[2].height));
	if (!(p->texture[2].img2))
		ft_g_error("Error\nTexture EA", p);
	p->texture[3].img2 = mlx_xpm_file_to_image(p->d.mlx_ptr, p->ea,
			&(p->texture[3].width), &(p->texture[3].height));
	if (!(p->texture[3].img2))
		ft_g_error("Error\nTexture WE\n", p);
	p->texture[4].img2 = mlx_xpm_file_to_image(p->d.mlx_ptr, p->sp,
			&(p->texture[4].width), &(p->texture[4].height));
	if (!(p->texture[4].img2))
		ft_g_error("Error\nTexture S", p);
	ft_get_texture_adress(p);
}

int	ft_path_texture(char *str, char **texture, t_map *p, int j)
{
	p->count2 = 0;
	if (*texture != NULL)
	{
		ft_g_error("Error\nTexture Invalide", p);
		return (0);
	}
	if (ft_charinstr(str, '.') == 0 || ft_charinstr(str, '/') == 0
		|| ft_strlen2(str) <= 2)
		ft_g_error("Error\nTexture Invalide", p);
	while (str[j] != '.')
	{
		if (str[j] != ' ' && str[j] != '.')
			ft_g_error("Error\nTexture Invalide", p);
		j++;
	}
	*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(str) + 1)));
	if (!(*texture))
		ft_g_error("Error\nTexture Invalide", p);
	while (str[j] != '\0')
	{
		(*texture)[p->count2++] = str[j];
		j++;
	}
	(*texture)[p->count2] = '\0';
	return (0);
}

void	ft_init_texture(t_map *p)
{
	if (p->r.side == 0 && p->r.raydirx < 0)
		p->t.texdir = 0;
	if (p->r.side == 0 && p->r.raydirx >= 0)
		p->t.texdir = 1;
	if (p->r.side == 1 && p->r.raydiry < 0)
		p->t.texdir = 2;
	if (p->r.side == 1 && p->r.raydiry >= 0)
		p->t.texdir = 3;
	if (p->r.side == 0)
		p->t.wallx = p->r.posy + p->r.walldist * p->r.raydiry;
	else
		p->t.wallx = p->r.posx + p->r.walldist * p->r.raydirx;
	p->t.wallx -= floor((p->t.wallx));
}
