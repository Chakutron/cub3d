/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/12/19 17:00:41 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	round_up(float nbr)
{
	if ((nbr - (int)nbr) >= 0.5)
		return ((int)(nbr) + 1);
	return ((int)nbr);
}

void	draw_line(t_data *data, int y0, int x0, int y1, int x1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (!(x0 == x1 && y0 == y1))
	{
		put_pixel_img(&(data->canvas), x0, y0, 0x000000FF);
        e2 = 2 * err;
        if (e2 > -dy)
		{
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            y0 += sy;
        }
    }
}

void	draw_square(t_data *data, int y_init, int x_init, int extra, int color)
{
	int y;
	int x;

	y = y_init;
	while (y < y_init + extra)
	{
		x = x_init;
		while (x < x_init + extra)
		{
			if (y >= 0 && y <= 450 && x >= 0 && x <= 450)
				put_pixel_img(&(data->canvas), x, y, color);
			x++;
		} 
		y++;
	}
}

void	draw_player(t_data *data)
{
	draw_line(data, 225, 225, 226 - data->player.y_temp * 2500, 226 + data->player.x_temp * 2500);
	draw_square(data, 220, 220, 10, 0x0000FF);
	draw_square(data, 225 - data->player.y_temp * 2500, 225 + data->player.x_temp * 2500, 3, 0x000000FF);
}

void	draw_map(t_data *data)
{
	int y;
	int x;
	int yy;
	int xx;
	int	y_offset;
	int	x_offset;

	y_offset = 50 * ((data->player.yy - (double)data->player.y) + 0.5);
	x_offset = 50 * ((data->player.xx - (double)data->player.x) + 0.5);
	y = data->player.y - 5;
	yy = 0;
	while (y <= data->player.y + 5)
	{
		x = data->player.x - 5;
		xx = 0;
		while (x <= data->player.x + 5)
		{
			if (y >= 0 && y < data->map.h && x >= 0 && x < data->map.w)
			{
				if (data->map.matrix[y][x] == ' ')
					draw_square(data, yy * 50 - y_offset, xx * 50 - x_offset, 49, 0x0000FF00);
				else if (data->map.matrix[y][x] == '0')
					draw_square(data, yy * 50 - y_offset, xx * 50 - x_offset, 49, 0x00FFFF00);
				else if (data->map.matrix[y][x] == '1')
					draw_square(data, yy * 50 - y_offset, xx * 50 - x_offset, 49, 0x00BB00FF);
			}
			else
				draw_square(data, yy * 50 - y_offset, xx * 50 - x_offset, 49, 0x0000FF00);
			x++;
			xx++;
		}
		y++;
		yy++;
	}
	draw_player(data);
}

void	calculate_vector_player(t_data *data)
{
	data->player.radians = data->player.angle * M_PI / 180.0;
	data->player.y_temp = 0.01 * sin(data->player.radians);
	data->player.x_temp = 0.01 * cos(data->player.radians);
}

int	render(t_data *data)
{
	if (data->endgame)
	{
		close_game(data);
		free_variables(data);
		exit(0);
	}
	data->canvas = new_img(WIDTH, HEIGHT, data);
	//put_img_to_img(&data->canvas, &(data->map.C_image), 0, 0);
	//put_img_to_img(&data->canvas, &(data->map.F_image), 0, 240);
	//raycasting(data);
	check_movement_keys(data);
	calculate_vector_player(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->canvas.ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->canvas.ptr);
	return (0);
}
