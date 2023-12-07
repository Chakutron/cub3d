/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/04/30 18:51:59 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_map(t_data *data)
{
	/*int		x;
	int		y;
	t_image	canvas;

	canvas = new_img(data->map_x * 50, data->map_y * 50 + 100, data);
	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{

			x++;
		}
		y++;
	}
	put_img_to_img(&canvas, &(data->image[15]), data->cursor_x - 25,
		data->cursor_y - 25);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, canvas.ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, canvas.ptr);*/
	(void)data;
}
