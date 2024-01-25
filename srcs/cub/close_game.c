/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/19 19:55:39 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* 
 * The `close_game` function cleans up and closes the game window. It shows the
 * mouse cursor, destroys the window, unloads images, and frees memory
 * associated with the mlx library.
 */

void	close_game(t_data *data)
{
	mlx_mouse_show(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	unload_images(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
