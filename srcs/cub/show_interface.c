/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/02 13:03:27 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_interface(t_data *data)
{
	/*int			x;
	static int	cloud_x = WINDOW_WIDTH / 2 - 200;

	x = 0;
	while (x < data->map_x)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image[17].ptr, x * 50, 0);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image[17].ptr, x * 50, data->map_y * 50 + 50);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->image[18].ptr, cloud_x, 0);
	cloud_x++;
	if (cloud_x > data->map_x * 50 - 50)
		cloud_x = -200;*/
	(void)data;
}
