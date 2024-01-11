/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/04 20:13:51 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		if (x0 >= 0 && x0 <= MINIMAP / data->ratio && y0 >= 0 && y0 <= MINIMAP / data->ratio)
		{
			if (data->ratio <= 2)
			{
				if ((y0 + x0) % 2 == 0)
					put_pixel_img(&(data->canvas), x0, y0, 0x000000FF);
			}
			else
				put_pixel_img(&(data->canvas), x0, y0, 0x000000FF);
		}
		else
			break;
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
			if (y >= 0 && y <= MINIMAP / data->ratio && x >= 0 && x <= MINIMAP / data->ratio)
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

void	draw_wall(t_data *data, int index)
{
	int y;
	int x;

	y = data->r3d[index].y_init;
	while (y < data->r3d[index].y_end)
	{
		x = data->r3d[index].x_init;
		while (x < data->r3d[index].x_end)
		{
			if (y >= 0 && y <= HEIGHT && x >= 0 && x <= WIDTH)
			{
				if (get_pixel_img(&data->canvas, x, y) == (unsigned int)data->map.cell.color || get_pixel_img(&data->canvas, x, y) == (unsigned int)data->map.floor.color)
				{
					if (data->r3d[index].wall == 'N')
						put_pixel_img(&(data->canvas), x, y, get_pixel_img(&data->map.NO_texture, data->r3d[index].texture_init, (y - data->r3d[index].y_init) * (49 / (data->r3d[index].y_end - data->r3d[index].y_init))));
					else if (data->r3d[index].wall == 'S')
						put_pixel_img(&(data->canvas), x, y, get_pixel_img(&data->map.SO_texture, data->r3d[index].texture_init, (y - data->r3d[index].y_init) * (49 / (data->r3d[index].y_end - data->r3d[index].y_init))));
					else if (data->r3d[index].wall == 'E')
						put_pixel_img(&(data->canvas), x, y, get_pixel_img(&data->map.EA_texture, data->r3d[index].texture_init, (y - data->r3d[index].y_init) * (49 / (data->r3d[index].y_end - data->r3d[index].y_init))));
					else if (data->r3d[index].wall == 'W')
						put_pixel_img(&(data->canvas), x, y, get_pixel_img(&data->map.WE_texture, data->r3d[index].texture_init, (y - data->r3d[index].y_init) * (49 / (data->r3d[index].y_end - data->r3d[index].y_init))));
				}
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	draw_square(data, (MINIMAP / 2 - MINIMAP / 45) / data->ratio, (MINIMAP / 2 - MINIMAP / 45) / data->ratio, (MINIMAP / 45 * 2) / data->ratio, 0x000000FF);
}

void	calculate_vector_player(t_data *data)
{
	data->player.radians = (data->player.angle * M_PI) / 180.0;
	data->player.y_temp = data->player.speed * sin(data->player.radians);
	data->player.x_temp = data->player.speed * cos(data->player.radians);
}

void	draw_rays(t_data *data)
{
	float	offset;
	double	y;
	double	x;
	double	dy;
	double	dx;
	float	i;
	int		index;
	float	angle;

	index = 0;
	i = -16;
	while (i <= 16)
	{
		angle = data->player.angle + i;
		if (angle < 0)
			angle += 360;
		if (angle > 360)
			angle -= 360;
		data->player.radians = (angle * M_PI) / 180.0;
		data->player.y_temp = 0.01 * sin(data->player.radians);
		data->player.x_temp = 0.01 * cos(data->player.radians);
		offset = 1;
		while (1)
		{
			y = data->player.y_temp * offset * 100;
			x = data->player.x_temp * offset * 100;
			dy = ((MINIMAP / 2 - y) - 4.5 * (MINIMAP / 9)) / (MINIMAP / 9) + data->player.yy;
			dx = ((MINIMAP / 2 + x) - 4.5 * (MINIMAP / 9)) / (MINIMAP / 9) + data->player.xx;
			if (data->map.matrix[(int)dy][(int)dx] == '1')
			{
				draw_square(data, MINIMAP / data->ratio / 2 - (data->player.y - (int)dy) * (MINIMAP / data->ratio / 9) - (data->player.yy - data->player.y) * (MINIMAP / data->ratio / 9), MINIMAP / data->ratio / 2 - (data->player.x - (int)dx) * (MINIMAP / data->ratio / 9) - (data->player.xx - data->player.x) * (MINIMAP / data->ratio / 9), (MINIMAP / data->ratio / 9) - 1 , 0x00FF0000);
				draw_line(data, MINIMAP / data->ratio / 2, MINIMAP / data->ratio / 2, (MINIMAP / 2 - y) / data->ratio, (MINIMAP / 2 + x) / data->ratio);
				float	y3;
				float	x3;
				y3 = data->player.y - dy;
				x3 = data->player.x - dx;
				data->r3d[index].y_init = 225 - ((MINIMAP / 9) * (HEIGHT - (MINIMAP / 9)) / (offset * cos((fabs(-i) * M_PI) / 180)));
				data->r3d[index].x_init = 900 - (index + 1) * (WIDTH / RAYS);
				data->r3d[index].y_end = 225 + ((MINIMAP / 9) * (HEIGHT - (MINIMAP / 9)) / (offset * cos((fabs(-i) * M_PI) / 180)));
				data->r3d[index].x_end = data->r3d[index].x_init + (WIDTH / RAYS);
				if (y3 <= 0.0 && fabs(y3) - (int)fabs(y3) < fabs(x3) - (int)fabs(x3) && data->map.matrix[(int)dy - 1][(int)dx] == '0' && data->player.yy < dy)
				{
					data->r3d[index].wall = 'N';
					data->r3d[index].texture_init = (int)((1 - (dx - (int)dx)) * 49);
				}
				else if (y3 >= 0.0 && fabs(y3) - (int)fabs(y3) < fabs(x3) - (int)fabs(x3) && data->map.matrix[(int)dy + 1][(int)dx] == '0' && data->player.yy > dy)
				{
					data->r3d[index].wall = 'S';
					data->r3d[index].texture_init = (int)((dx - (int)dx) * 49);
				}
				else if (x3 >= 0.0 && fabs(y3) - (int)fabs(y3) > fabs(x3) - (int)fabs(x3) && data->map.matrix[(int)dy][(int)dx + 1] == '0' && data->player.xx > dx)
				{
					data->r3d[index].wall = 'E';
					data->r3d[index].texture_init = (int)((1 - (dy - (int)dy)) * 49);
				}
				else if (x3 <= 0.0 && fabs(y3) - (int)fabs(y3) > fabs(x3) - (int)fabs(x3) && data->map.matrix[(int)dy][(int)dx - 1] == '0' && data->player.xx < dx)
				{
					data->r3d[index].wall = 'W';
					data->r3d[index].texture_init = (int)((dy - (int)dy) * 49);
				}
				draw_wall(data, index);
				break;
			}
			offset += 0.1;
		}
		i += 0.25;
		index++;
	}
}

void	draw_minimap(t_data *data)
{
	int y;
	int x;
	int yy;
	int xx;
	int	y_offset;
	int	x_offset;

	draw_square(data, 0, 0, MINIMAP / data->ratio, 0x00000000);
	y_offset = MINIMAP / data->ratio / 9 * ((data->player.yy - (double)data->player.y) + 0.5);
	x_offset = MINIMAP / data->ratio / 9 * ((data->player.xx - (double)data->player.x) + 0.5);
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
					draw_square(data, yy * MINIMAP / data->ratio / 9 - y_offset, xx * MINIMAP / data->ratio / 9 - x_offset, MINIMAP / data->ratio / 9 - 1, 0x0000FF00);
				else if (data->map.matrix[y][x] == '0')
					draw_square(data, yy * MINIMAP / data->ratio / 9 - y_offset, xx * MINIMAP / data->ratio / 9 - x_offset, MINIMAP / data->ratio / 9 - 1, 0x00FFFF00);
				else if (data->map.matrix[y][x] == '1')
					draw_square(data, yy * MINIMAP / data->ratio / 9 - y_offset, xx * MINIMAP / data->ratio / 9 - x_offset, MINIMAP / data->ratio / 9 - 1, 0x00BB00FF);
			}
			else
				draw_square(data, yy * MINIMAP / data->ratio / 9 - y_offset, xx * MINIMAP / data->ratio / 9 - x_offset, MINIMAP / data->ratio / 9 - 1, 0xFF00FF00);
			x++;
			xx++;
		}
		y++;
		yy++;
	}
}

void	draw_background(t_data *data)
{
	put_img_to_img(&data->canvas, &(data->map.C_image), 0, 0);
	put_img_to_img(&data->canvas, &(data->map.F_image), 0, HEIGHT / 2);
}

void	update(t_data *data)
{
	data->canvas = new_img(WIDTH, HEIGHT, data);
	draw_background(data);
	draw_minimap(data);
	draw_rays(data);
	draw_player(data);
	calculate_vector_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->canvas.ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->canvas.ptr);
}

int	render(t_data *data)
{
	if (data->endgame)
	{
		close_game(data);
		free_variables(data);
		exit(0);
	}
	check_movement_keys(data);
	return (0);
}