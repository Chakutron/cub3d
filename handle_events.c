/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/11 21:15:03 by mchiboub         ###   ########.fr       */
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
		if (data->map.matrix[(int)(data->player.yy - 10 * data->player.y_temp)][(int)(data->player.xx + 10 * data->player.x_temp)] == '1')
		{
			data->player.yy = y_old;
			data->player.xx = x_old;
		}
		data->player.y = data->player.yy;
		data->player.x = data->player.xx;
		update(data);
	}
	if (data->key.s)
	{
		data->player.yy += data->player.y_temp;
		data->player.xx -= data->player.x_temp;
		if (data->map.matrix[(int)(data->player.yy + 10 * data->player.y_temp)][(int)(data->player.xx - 10 * data->player.x_temp)] == '1')
		{
			data->player.yy = y_old;
			data->player.xx = x_old;
		}
		data->player.y = data->player.yy;
		data->player.x = data->player.xx;
		update(data);
	}
	if (data->key.a)
	{
		data->player.angle += 1 + data->cursor_x;
		if (data->player.angle > 360)
			data->player.angle -= 360;
		update(data);
	}
	if (data->key.d)
	{
		data->player.angle -= 1 + data->cursor_x;
		if (data->player.angle < 0)
			data->player.angle += 360;
		update(data);
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
	mlx_mouse_show(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	unload_images(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	(void)y;
	if (x < WIDTH / 2)
	{
		data->key.a = 1 + data->key.d;
		data->cursor_x = abs(WIDTH / 2 - x) / 10;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, WIDTH / 2, HEIGHT / 2);
	}
	else
		data->key.a = 0;
	if (x > WIDTH / 2)
	{
		data->key.d = 1 + data->key.a;
		data->cursor_x = abs(WIDTH / 2 - x) / 10;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, WIDTH / 2, HEIGHT / 2);
	}
	else
		data->key.d = 0;
	if (data->key.a == 0 && data->key.d == 0)
		data->cursor_x = 0;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		data->endgame = 1;
	if (keysym == 119 || keysym == 65362)
		data->key.w = -1 + data->key.s;
	if (keysym == 115 || keysym == 65364)
		data->key.s = 1 + data->key.w;
	if (keysym == 97 || keysym == 65361)
		data->key.a = -1 + data->key.d;
	if (keysym == 100 || keysym == 65363)
		data->key.d = 1 + data->key.a;	
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
	if (keysym ==  65451)
	{
		data->ratio -= 1;
		if (data->ratio < 1)
			data->ratio = 1;
		update(data);
	}
	if (keysym ==  65453)
	{
		data->ratio += 1;
		if (data->ratio > 5)
			data->ratio = 5;
		update(data);
	}
	return (0);
}
