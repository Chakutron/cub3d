/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/22 17:21:22 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `update` function refreshes the game display by creating a new canvas
 * image, drawing various elements such as the background, minimap, rays,
 * player, and walk animation, and then putting the updated canvas onto the game
 * window. Finally, it destroys the temporary canvas image to avoid memory leaks.
 */

void	update(t_data *data)
{
	data->canvas = new_img(WIDTH, HEIGHT, data);
	draw_background(data);
	draw_minimap(data);
	draw_rays(data);
	draw_player(data);
	calculate_vector_player(data);
	draw_walk(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->canvas.ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->canvas.ptr);
}
