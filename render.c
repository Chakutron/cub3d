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

void	check_movement(t_data *data)
{	
	(void)data;
	/*if (data->refresh && data->gamestart > 0)
	{
		show_map(data);
		data->refresh = 0;
		data->start = clock();
		if (data->movement)
		{
			data->movement += 1;
			if (data->movement >= 3)
				data->movement = 0;
		}
	}*/
}

int	render(t_data *data)
{
	t_image	canvas;
	/*int			end;
	int			num;

	end = clock();
	if ((double)(end - data->start) / CLOCKS_PER_SEC > (1.0 / data->fps))
	{
		work_animations(data);
		srand(clock());
		num = rand() % data->fps;
		if (num <= (data->fps / 5))
			enemy_move(data);
		data->refresh = 1;
	}
	if (data->enemies > 0)
		check_enemy_collision(data);
	if (data->endgame)
	{
		mlx_mouse_show(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	else
		check_movement(data);*/
	if (data->endgame)
	{
		close_game(data);
		free_variables(data);
		exit(0);
	}
	canvas = new_img(640, 480, data);
	put_img_to_img(&canvas, &(data->map.C_image), 0, 0);
	put_img_to_img(&canvas, &(data->map.F_image), 0, 240);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, canvas.ptr, 0, 0);
	raycasting(data);
	mlx_destroy_image(data->mlx_ptr, canvas.ptr);
	return (0);
}
