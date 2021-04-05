/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:56:49 by fgomez            #+#    #+#             */
/*   Updated: 2021/03/31 13:14:02 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_murs_util(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen2(char *str)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int	ft_charinstr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_depart(char c, t_map *p, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		p->depart = c;
		p->dx = i;
		p->dy = j;
		return (1);
	}
	return (0);
}

int	ft_atoi2(const char *str, t_map *p)
{
	int		sum;

	sum = 0;
	if (str[1] != ' ' || ft_charinstr((char *)str, ',') == 1)
		ft_g_error("Error\nInvalide Screen", p);
	while (str[p->i] == ' ' || str[p->i] == '\t'
		|| str[p->i] == ',' || str[p->i] == '\n'
		|| str[p->i] == '\r' || str[p->i] == '\v'
		|| str[p->i] == '\f')
		p->i++;
	if (str[p->i] == '-' || str[p->i] == '+')
		ft_g_error("Error\nInvalide Screen", p);
	while (str[p->i] >= '0' && str[p->i] <= '9')
	{
		if (sum > 21474636)
			break ;
		sum = (sum * 10) + (str[p->i] - 48);
		p->i++;
	}
	while (str[p->i] >= '0' && str[p->i] <= '9')
		p->i++;
	return (sum);
}
