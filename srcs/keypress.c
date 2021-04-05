/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:06:52 by fgomez            #+#    #+#             */
/*   Updated: 2021/03/31 11:07:51 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_keypress(int keycode, t_map *params)
{
	if (keycode == FORWARD_W_Z)
		params->forward = 1;
	else if (keycode == BACK_S_S)
		params->backward = 1;
	else if (keycode == LEFT_A_Q)
		params->left = 1;
	else if (keycode == RIGHT_D_D)
		params->right = 1;
	else if (keycode == ROTATE_LEFT)
		params->rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		params->rotate_right = 1;
	else if (keycode == ESCAPE)
		ft_g_error("GAME OVER", params);
	return (1);
}

int	ft_keyrelease(int keycode, t_map *params)
{
	if (keycode == FORWARD_W_Z)
		params->forward = 0;
	else if (keycode == BACK_S_S)
		params->backward = 0;
	else if (keycode == LEFT_A_Q)
		params->left = 0;
	else if (keycode == RIGHT_D_D)
		params->right = 0;
	else if (keycode == ROTATE_LEFT)
		params->rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		params->rotate_right = 0;
	return (1);
}
