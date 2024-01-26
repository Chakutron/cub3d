/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   south_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/26 15:57:54 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `south_wall` function is responsible for drawing the texture of an
 * south-facing wall onto the canvas at the specified `(x, y)` coordinates. It
 * retrieves the pixel color from the south-facing wall texture stored in
 * `data->map.SO_texture` and applies it to the canvas. The texture offset is
 * calculated based on the difference in `y` coordinates within the wall segment.
 */

void	south_wall(t_data *data, int index, int y, int x)
{
	put_pixel_img(&(data->canvas), x, y, get_pixel_img(&data->map.so_texture,
			data->r3d[index].texture_init, (y - data->r3d[index].y_init)
			* (49 / (data->r3d[index].y_end - data->r3d[index].y_init))));
}
