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

void	free_variables(t_data *data)
{
	int	i;
	
	if (data->map.h && data->map.w)
	{
		i = 0;
		while (i <= data->map.h)
		{
			free(data->map.matrix[i]);
			i++;
		}
		free(data->map.matrix);
	}
	if (data->map.info.n)
		free(data->map.NO_file);
	if (data->map.info.s)
		free(data->map.SO_file);
	if (data->map.info.w)
		free(data->map.WE_file);
	if (data->map.info.e)
		free(data->map.EA_file);
}

int	x_press(t_data *data)
{
	data->endgame = 1;
	return (0);
}

void	close_game(t_data *data)
{
	//mlx_mouse_show(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	//unload_images(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		data->endgame = 1;
	//check_movement_keys(keysym, data, data->player.x, data->player.y);
	return (0);
}
