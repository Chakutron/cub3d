/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_floor_and_cell.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 20:00:07 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			put_pixel_img(&(data->map.F_image), x, y, data->map.floor.color);
			put_pixel_img(&(data->map.C_image), x, y, data->map.cell.color);
			x++;
		}
		y++;
	}
}
