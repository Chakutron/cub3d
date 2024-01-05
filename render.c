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
		if (x0 >= 0 && x0 <= WIDTH / 2 && y0 >= 0 && y0 <= HEIGHT)
			put_pixel_img(&(data->canvas), x0, y0, 0x000000FF);
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
			if (y >= 0 && y <= 450 && x >= 0 && x <= 450)
				put_pixel_img(&(data->canvas), x, y, color);
			x++;
		} 
		y++;
	}
}

void	draw_square_N(t_data *data, int y_init, int x_init, int y_end, int x_end)
{
	int y;
	int x;

	y = y_init;
	while (y < y_end)
	{
		x = x_init;
		while (x < x_end)
		{
			if (y >= 0 && y <= 450 && x >= 450 && x <= 900)
				put_pixel_img(&(data->canvas), x, y, 0x00FF0000);
			x++;
		} 
		y++;
	}
}

void	draw_square_S(t_data *data, int y_init, int x_init, int y_end, int x_end)
{
	int y;
	int x;

	y = y_init;
	while (y < y_end)
	{
		x = x_init;
		while (x < x_end)
		{
			if (y >= 0 && y <= 450 && x >= 450 && x <= 900)
				put_pixel_img(&(data->canvas), x, y, 0x000000FF);
			x++;
		} 
		y++;
	}
}

void	draw_square_E(t_data *data, int y_init, int x_init, int y_end, int x_end)
{
	int y;
	int x;

	y = y_init;
	while (y < y_end)
	{
		x = x_init;
		while (x < x_end)
		{
			if (y >= 0 && y <= 450 && x >= 450 && x <= 900)
				put_pixel_img(&(data->canvas), x, y, 0x0000FF00);
			x++;
		} 
		y++;
	}
}

void	draw_square_W(t_data *data, int y_init, int x_init, int y_end, int x_end)
{
	int y;
	int x;

	y = y_init;
	while (y < y_end)
	{
		x = x_init;
		while (x < x_end)
		{
			if (y >= 0 && y <= 450 && x >= 450 && x <= 900)
				put_pixel_img(&(data->canvas), x, y, 0x00FF00FF);
			x++;
		} 
		y++;
	}
}

void	calculate_vector_player(t_data *data)
{
	data->player.radians = (data->player.angle * M_PI) / 180.0;
	data->player.y_temp = data->player.speed * sin(data->player.radians);
	data->player.x_temp = data->player.speed * cos(data->player.radians);
}

void	draw_rays2D_v1(t_data *data)
{
	int		offset;
	double	y;
	double	x;
	double	dy;
	double	dx;
	float	i;

	i = 0;
	while (i <= data->rc_max_angle + 1)
	{
		data->player.radians = ((data->player.angle + i )* M_PI) / 180.0;
		data->player.y_temp = 0.01 * sin(data->player.radians);
		data->player.x_temp = 0.01 * cos(data->player.radians);
		offset = 1;
		while (1)
		{
			y = data->player.y_temp * offset * 100;
			x = data->player.x_temp * offset * 100;
			dy = ((225 - y) - 4.5 * 50) / 50 + data->player.yy;
			dx = ((225 + x) - 4.5 * 50) / 50 + data->player.xx;
			if (data->map.matrix[(int)dy][(int)dx] == '1')
			{
				draw_line(data, 225, 225, 225 - y, 225 + x);
				data->rc_dist_offset = (int)((WIDTH / 2) / data->rc_max_angle) / 2;

				float	y3;
				float	x3;
				y3 = data->player.y - dy;
				x3 = data->player.x - dx;

				//printf("P(%i, %i) W(%f, %f) D(%f, %f)\n", data->player.y, data->player.x, dy, dx, -y3, -x3);
				
				if (y3 >= 0.0 && fabs(y3) - (int)fabs(y3) < fabs(x3) - (int)fabs(x3))
				{
					if (i < 0)
						draw_square_N(data, 225 - (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
					else
						draw_square_N(data, 225 - (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
				}
				else if (y3 < 0.0 && (fabs(y3) - (int)fabs(y3)) < (fabs(x3) - (int)fabs(x3)))
				{
					if (i < 0)
						draw_square_S(data, 225 - (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
					else
						draw_square_S(data, 225 - (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
				}
				else if (x3 >= 0.0 && (fabs(y3) - (int)fabs(y3)) > (fabs(x3) - (int)fabs(x3)))
				{
					if (i < 0)
						draw_square_E(data, 225 - (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
					else
						draw_square_E(data, 225 - (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
				}
				else if (x3 < 0.0 && (fabs(y3) - (int)fabs(y3)) > (fabs(x3) - (int)fabs(x3)))
				{
					if (i < 0)
						draw_square_W(data, 225 - (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
					else
						draw_square_W(data, 225 - (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
				}
				//draw_square2(data, 225 - 225 * 50 / (49 + offset), 675 - i * 9 - 9, 225 + 225 * 50 / (49 + offset), 675 - i * 9);
				break;
			}
			offset++;
		}
		i += 0.25;
	}
}

void	draw_rays2D_v2(t_data *data)
{
	int		offset;
	double	y;
	double	x;
	double	dy;
	double	dx;
	float	i;

	i = 0;
	while (i >= -(data->rc_max_angle + 1))
	{
		data->player.radians = ((data->player.angle + i )* M_PI) / 180.0;
		data->player.y_temp = 0.01 * sin(data->player.radians);
		data->player.x_temp = 0.01 * cos(data->player.radians);
		offset = 1;
		while (1)
		{
			y = data->player.y_temp * offset * 100;
			x = data->player.x_temp * offset * 100;
			dy = ((225 - y) - 4.5 * 50) / 50 + data->player.yy;
			dx = ((225 + x) - 4.5 * 50) / 50 + data->player.xx;
			if (data->map.matrix[(int)dy][(int)dx] == '1')
			{
				draw_line(data, 225, 225, 225 - y, 225 + x);
				data->rc_dist_offset = (int)((WIDTH / 2) / data->rc_max_angle) / 2;

				float	y3;
				float	x3;
				y3 = data->player.y - dy;
				x3 = data->player.x - dx;

				//printf("P(%i, %i) W(%f, %f) D(%f, %f)\n", data->player.y, data->player.x, dy, dx, -y3, -x3);
				
				if (y3 >= 0.0 && fabs(y3) - (int)fabs(y3) < fabs(x3) - (int)fabs(x3))
				{
					if (i < 0)
						draw_square_N(data, 225 - (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
					else
						draw_square_N(data, 225 - (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
				}
				else if (y3 < 0.0 && (fabs(y3) - (int)fabs(y3)) < (fabs(x3) - (int)fabs(x3)))
				{
					if (i < 0)
						draw_square_S(data, 225 - (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
					else
						draw_square_S(data, 225 - (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
				}
				else if (x3 >= 0.0 && (fabs(y3) - (int)fabs(y3)) > (fabs(x3) - (int)fabs(x3)))
				{
					if (i < 0)
						draw_square_E(data, 225 - (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
					else
						draw_square_E(data, 225 - (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
				}
				else if (x3 < 0.0 && (fabs(y3) - (int)fabs(y3)) > (fabs(x3) - (int)fabs(x3)))
				{
					if (i < 0)
						draw_square_W(data, 225 - (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos((-i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
					else
						draw_square_W(data, 225 - (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset - data->rc_dist_offset, 225 + (50 * (HEIGHT - 50) / (offset * cos(( i * M_PI) / 180))), 675 - i * data->rc_dist_offset + data->rc_dist_offset);
				}
				//draw_square2(data, 225 - 225 * 50 / (49 + offset), 675 - i * 9 - 9, 225 + 225 * 50 / (49 + offset), 675 - i * 9);
				break;
			}
			offset++;
		}
		i -= 0.25;
	}
}

void	draw_player(t_data *data)
{
	draw_square(data, 220, 220, 10, 0x0000FF);
	put_img_to_img(&data->canvas, &(data->map.C_image), 450, 0);
	put_img_to_img(&data->canvas, &(data->map.F_image), 450, 225);
	draw_rays2D_v1(data);
	draw_rays2D_v2(data);
	calculate_vector_player(data);
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

int	render(t_data *data)
{
	if (data->endgame)
	{
		close_game(data);
		free_variables(data);
		exit(0);
	}
	data->canvas = new_img(WIDTH, HEIGHT, data);
	check_movement_keys(data);
	calculate_vector_player(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->canvas.ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->canvas.ptr);
	return (0);
}
