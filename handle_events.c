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

void	check_movement_keys(t_data *data)
{
	double x_old;
	double y_old;

	x_old = data->player.xx;
	y_old = data->player.yy;
	if (data->key.w)
	{
		data->player.yy -= data->player.y_temp;
		data->player.xx += data->player.x_temp;
		if (data->map.matrix[(int)data->player.yy][(int)data->player.xx] != '0')
		{
			data->player.yy = y_old;
			data->player.xx = x_old;
		}
		data->player.y = data->player.yy;
		data->player.x = data->player.xx;
	}
	if (data->key.s)
	{
		data->player.yy += data->player.y_temp;
		data->player.xx -= data->player.x_temp;
		if (data->map.matrix[(int)data->player.yy][(int)data->player.xx] != '0')
		{
			data->player.yy = y_old;
			data->player.xx = x_old;
		}
		data->player.y = data->player.yy;
		data->player.x = data->player.xx;
	}
	if (data->key.a)
	{
		data->player.angle += 1;
		if (data->player.angle > 360)
			data->player.angle -= 360;
	}
	if (data->key.d)
	{
		data->player.angle -= 1;
		if (data->player.angle < 0)
			data->player.angle += 360;
	}
}

void	free_variables(t_data *data)
{
	int	i;
	
	if (data->map.h && data->map.w)
	{
		i = 0;
		while (i < data->map.h)
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
	unload_images(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		data->endgame = 1;
	if (keysym == 119 || keysym == 65362)
		data->key.w = 1;
	if (keysym == 115 || keysym == 65364)
		data->key.s = 1;
	if (keysym == 97 || keysym == 65361)
		data->key.a = 1;
	if (keysym == 100 || keysym == 65363)
		data->key.d = 1;	
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == 119 || keysym == 65362)
		data->key.w = 0;
	if (keysym == 115 || keysym == 65364)
		data->key.s = 0;
	if (keysym == 97 || keysym == 65361)
		data->key.a = 0;
	if (keysym == 100 || keysym == 65363)
		data->key.d = 0;
	return (0);
}