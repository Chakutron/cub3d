/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/22 17:38:41 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	north_wall(t_data *data, int index, int y, int x)
{
	put_pixel_img(&(data->canvas), x, y, get_pixel_img(&data->map.NO_texture,
			data->r3d[index].texture_init, (y - data->r3d[index].y_init)
			* (49 / (data->r3d[index].y_end - data->r3d[index].y_init))));
}
