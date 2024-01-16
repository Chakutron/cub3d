/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/16 18:15:55 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update(t_data *data)
{
	data->canvas = new_img(WIDTH, HEIGHT, data);
	draw_background(data);
	draw_minimap(data);
	draw_rays(data);
	draw_player(data);
	calculate_vector_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->canvas.ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->canvas.ptr);
}
