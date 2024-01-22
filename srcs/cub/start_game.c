/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <mchiboub@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:30:45 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/19 19:56:01 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_game(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		print_error(data, 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH,
			HEIGHT, "Cub3D by Chaku & Trorioll");
	if (!data->win_ptr)
		print_error(data, 1);
	else
	{
		mlx_loop_hook(data->mlx_ptr, &render, data);
		mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
		mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask,
			&handle_keyrelease, data);
		mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask,
			&handle_mouse_move, data);
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, WIDTH / 2, HEIGHT / 2);
		mlx_hook(data->win_ptr, 17, 1L << 0, &x_press, data);
		mlx_do_key_autorepeaton(data->mlx_ptr);
		//mlx_mouse_hide(data->mlx_ptr, data->win_ptr);
		load_images(data);
		printf("\n--- GAME STARTED ---\n");
		update(data);
		mlx_loop(data->mlx_ptr);
	}
}
