/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/16 18:16:03 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rick(t_data *data)
{
	put_img_to_img(&data->canvas, &(data->rick.texture[data->rick.index]), WIDTH - 50, HEIGHT - 80);
	data->timer += 0.075;
	if (data->timer > 1)
	{
		data->rick.index++;
		if (data->rick.index > 26)
			data->rick.index = 0;
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
	update(data);
	return (0);
}
