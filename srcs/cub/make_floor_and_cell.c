/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_floor_and_cell.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/26 15:57:15 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `make_floor_and_cell` function fills two images (`F_image` and `C_image`)
 * with colors representing the floor and ceiling, respectively, using the
 * specified colors stored in the `data` structure.
 */

void	make_floor_and_cell(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (HEIGHT / 2))
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel_img(&(data->map.f_image), x, y, data->map.floor.color);
			put_pixel_img(&(data->map.c_image), x, y, data->map.cell.color);
			x++;
		}
		y++;
	}
}
