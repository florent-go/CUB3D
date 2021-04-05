/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_color_reso.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:45:32 by fgomez            #+#    #+#             */
/*   Updated: 2021/04/01 09:49:53 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_atoi(const char *s, t_map *p)
{
	size_t	res;
	int		sign;

	sign = 1;
	res = 0;
	while (s[p->i] && (s[p->i] == ' ' || s[p->i] == '\n' || s[p->i] == '\t'
			|| s[p->i] == '\v' || s[p->i] == '\f'
			|| s[p->i] == '\r'))
		p->i++;
	if (s[p->i] == '-')
		sign = -1;
	if (s[p->i] == '-' || *s == '+')
		p->i++;
	if (s[p->i] && (s[p->i] < '0' || s[p->i] > '9'))
		return (-1);
	while (s[p->i] && s[p->i] >= '0' && s[p->i] <= '9')
	{
		res = res * 10 + (s[p->i] - 48);
		p->i++;
	}
	return (res * sign);
}

int	ft_color(const char *s, t_map *p)
{
	p->ro = ft_atoi(s, p);
	if (s[p->i] == ',')
		p->i++;
	p->gr = ft_atoi(s, p);
	if (s[p->i] == ',')
		p->i++;
	p->bl = ft_atoi(s, p);
	if (s[p->i] == ',')
		p->i++;
	if (p->ro < 0 || p->ro > 255)
		ft_g_error("Error\nColor Rouge", p);
	if (p->ro < 0 || p->ro > 255)
		ft_g_error("Error\nColor Vert", p);
	if (p->ro < 0 || p->ro > 255)
		ft_g_error("Error\nColor Blue", p);
	return (p->ro << 16 | p->gr << 8 | p->bl);
}

void	ft_resolution(char **s, t_map *p)
{
	int			i;

	i = 0;
	p->i = 1;
	if (p->sizelignes > 0 && (p->no == NULL || p->so == NULL
			|| p->we == NULL || p->ea == NULL || p->sp == NULL))
		ft_g_error("Error\n Texture Invalide", p);
	if ((p->no != NULL || p->so != NULL || p->we != NULL
			|| p->ea != NULL || p->sp != NULL) && (p->screenx == 0
			|| p->screeny == 0))
		ft_g_error("Error\nParsing", p);
	if (*s[i] == 'R')
	{
		if (p->screenx != 0 && p->screeny != 0)
			ft_g_error("Error\nScreen double difine", p);
		p->screenx = ft_atoi2(*s, p);
		p->screeny = ft_atoi2(*s, p);
		if (ft_atoi2(*s, p) > 0 || p->screenx == 0 || p->screeny == 0)
			ft_g_error("Error\nScreen undifine", p);
	}
	else if (*s[i] == 'F')
		p->f = ft_color(*s, p);
	else if (*s[i] == 'C')
		p->c = ft_color(*s, p);
}
