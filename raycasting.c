/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:03:42 by ocassany          #+#    #+#             */
/*   Updated: 2023/12/19 17:22:03 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_data *data)
{
	data->rc.dir_x = -1.0;
	data->rc.dir_y = 0.0;
	data->rc.plane_x = 0.0;
	data->rc.plane_y = 0.66;

	data->rc.line_height = (int)(2 * HEIGHT / data->rc.perp_wall_dist);
	data->rc.draw_start = (-data->rc.line_height) / 2 + (HEIGHT / 2);
	if (data->rc.draw_start < 0)
		data->rc.draw_start = 0;
	data->rc.draw_end = (data->rc.line_height / 2) + (HEIGHT / 2);
	if (data->rc.draw_end >= HEIGHT)
		data->rc.draw_start = HEIGHT - 1;
}

void	shortest_ray(t_data *data)
{
	if (data->rc.side == 0)
		data->rc.perp_wall_dist = data->rc.side_dist_x - data->rc.delta_dist_x;
	else if (data->rc.side == 1)
		data->rc.perp_wall_dist = data->rc.side_dist_y - data->rc.delta_dist_y;
}

void	dda(t_data *data)
{
	while (data->rc.hit == 0)
	{
		if (data->rc.side_dist_x < data->rc.side_dist_y)
		{
			data->rc.side_dist_x += data->rc.delta_dist_x;
			data->player.x += data->rc.step_x;
			data->rc.side = 0;
		}
		else
		{
			data->rc.side_dist_y += data->rc.delta_dist_y;
			data->player.y += data->rc.step_y;
			data->rc.side = 1;
		}
		if (data->map.matrix[data->player.y][data->player.x] == 1)
			data->rc.hit = 1;
	}
}

void	side_dist(t_data *data)
{
	if (data->rc.ray_dir_x < 0)
	{
		data->rc.step_x = -1;
		data->rc.side_dist_x = (data->player.xx - data->player.x) * data->rc.delta_dist_x;
	}
	else
	{
		data->rc.step_x = 1;
		data->rc.side_dist_x = (data->player.x + 1 - data->player.xx) * data->rc.delta_dist_x;
	}
	if (data->rc.ray_dir_y < 0)
	{
		data->rc.step_y = -1;
		data->rc.side_dist_y = (data->player.yy - data->player.y) * data->rc.delta_dist_y;
	}
	else
	{
		data->rc.step_y = 1;
		data->rc.side_dist_y = (data->player.y + 1 - data->player.yy) * data->rc.delta_dist_y;
	}
}

void	delta_dist(t_data *data)
{
	if (data->rc.ray_dir_x == 0)
		data->rc.delta_dist_x = INFINITY;
	else
		data->rc.delta_dist_x = sqrt(1 + (data->rc.ray_dir_y * data->rc.ray_dir_y) / (data->rc.ray_dir_x * data->rc.ray_dir_x));
	if (data->rc.ray_dir_y == 0)
		data->rc.delta_dist_y = INFINITY;
	else
		data->rc.delta_dist_y = sqrt(1 + (data->rc.ray_dir_x * data->rc.ray_dir_x) / (data->rc.ray_dir_y * data->rc.ray_dir_y));
}

void	rays_vector(int x, int w, t_data *data)
{
	data->rc.camera_x = 2 * x / w - 1;
	data->rc.ray_dir_x = data->rc.dir_x + (data->rc.plane_x * data->rc.camera_x);
	data->rc.ray_dir_y = data->rc.dir_y + (data->rc.plane_y * data->rc.camera_x);
}

void	raycasting(t_data *data)
{
	int		x;
	int		w;
	
	w = 50;
	x = 0;
	while (x < w)
	{
		rays_vector(x, w, data);
		delta_dist(data);
		side_dist(data);
		dda(data);
		shortest_ray(data);
		draw_line(data);
		x++;
	}
}
