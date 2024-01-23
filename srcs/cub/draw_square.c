/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/23 18:35:25 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_data *data, int y_init, int x_init, int extra)
{
	int	y;
	int	x;

	y = y_init;
	while (y < y_init + extra)
	{
		x = x_init;
		while (x < x_init + extra)
		{
			if (y >= 0 && y <= MINIMAP / data->ratio && x >= 0
				&& x <= MINIMAP / data->ratio)
			{
				if (data->ratio <= 2)
				{
					if ((y + x) % 2 == 0)
						put_pixel_img(&(data->canvas), x, y, color);
				}
				else
					put_pixel_img(&(data->canvas), x, y, color);
			}
			x++;
		}
		y++;
	}
}
