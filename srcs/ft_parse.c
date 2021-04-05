/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:23:54 by fgomez            #+#    #+#             */
/*   Updated: 2021/04/01 11:38:47 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_texture(char *str, t_map *p)
{
	int			i;
	static int	j = 0;

	i = 0;
	if (str[i] == 'S' && str[i + 1] == 'O')
		ft_path_texture(str, &p->no, p, 2);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		ft_path_texture(str, &p->so, p, 2);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_path_texture(str, &p->we, p, 2);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_path_texture(str, &p->ea, p, 2);
	else if (str[i] == 'S' && str[i + 1] != 'O')
		ft_path_texture(str, &p->sp, p, 1);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
		&& str[0] != 'R' && str[0] != 'F' && str[0] != 'C'
		&& str[0] > 65 && str[0] < 122)
		ft_g_error("Error\nMap Invalide", p);
	j++;
}

int	ft_parsing_map(char *fichier, t_map *p)
{
	int			fd;
	int			ret;
	char		*str;

	ret = 1;
	str = NULL;
	fd = open(fichier, O_RDONLY);
	p->map = malloc(sizeof(char *) * p->nblignes);
	if (!(p->map))
		return (0);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		if (ft_is_map(str) == 1)
			ft_copy_map(str, p);
		free(str);
	}
	close(fd);
	return (0);
}

void	ft_parse(char *fichier, t_map *p)
{
	int			fd;
	int			ret;
	char		*str;

	ret = 1;
	str = NULL;
	fd = open(fichier, O_DIRECTORY);
	if (fd != -1)
		ft_g_error("Error\nInvalide : is a directory\n", p);
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		ft_g_error("Error\nFichier .cub invalide\n", p);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str);
		ft_resolution(&str, p);
		ft_texture(str, p);
		ft_map(str, p);
		free(str);
	}
	close(fd);
	if (p->c < 0 || p->f < 0)
		ft_g_error("Error\nF or C Invalide", p);
	if (p->sizelignes == 0 || p->nblignes == 0)
		ft_g_error("Error\nMap absente\n", p);
	ft_parsing_map(fichier, p);
}
