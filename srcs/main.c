/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:08:15 by fgomez            #+#    #+#             */
/*   Updated: 2021/04/01 09:49:34 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_arg2(char *str, t_map *p)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
			return (ft_g_error("Error\nFichier invalides\n", p));
	}
	if (!(str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b'))
		return (ft_g_error("Error\nExtension invalides\n", p));
	return (1);
}

int	ft_check_arg3(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'e' && str[i - 2] == 'v' && str[i - 3] == 'a'
		&& str[i - 4] == 's' && str[i - 5] == '-' && str[i - 6] == '-'
		&& ft_strlen(str) < 7)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_map	p;

	ft_initialisation(&p);
	if (argc == 2 || (argc == 3 && ft_check_arg3(argv[2]) == 1))
	{
		if (ft_check_arg2(argv[1], &p) == 1)
			ft_parse(argv[1], &p);
	}
	else
		return (ft_g_error("Error\nArguments invalides", &p));
	ft_init_sprite(&p);
	ft_mlx(&p);
	return (0);
}
