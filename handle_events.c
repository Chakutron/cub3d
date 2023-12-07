/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/02 13:13:22 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_movement_keys(int keysym, t_data *data, int x, int y)
{
	(void)data;
	if (keysym == 119 || keysym == 65362)
	{
		// up
		y--;
	}
	else if (keysym == 115 || keysym == 65364)
	{
		// down
		y++;
	}
	else if (keysym == 97 || keysym == 65361)
	{
		// left
		x--;
	}
	else if (keysym == 100 || keysym == 65363)
	{
		// right
		x++;
	}
}

void	close_game(t_data *data)
{
	unload_images(data);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_game(data);
	check_movement_keys(keysym, data, data->player.x, data->player.y);
	return (0);
}
