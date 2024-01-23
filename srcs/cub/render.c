/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/22 19:15:12 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_walk(t_data *data)
{
	put_img_to_img(&data->canvas,
		&(data->player.walk.texture[data->player.walk.index]),
		WIDTH / 2 - 225, HEIGHT - data->player.walk_offset);
	if (data->player.walk_offset == 300)
		data->player.walk_offset = 245;
	data->timer += 0.075;
	if (data->timer > 1)
	{
		data->player.walk.index++;
		if (data->player.walk.index > 20)
			data->player.walk.index = 0;
		data->timer = 0.0;
	}
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
