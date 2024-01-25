/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/16 18:11:26 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *data)
{
	data->ds.y_init = (MINIMAP / 2 - MINIMAP / 45) / data->ratio;
	data->ds.x_init = (MINIMAP / 2 - MINIMAP / 45) / data->ratio;
	data->ds.extra = (MINIMAP / 45 * 2)
		/ data->ratio;
	data->ds.color = 0x000000FF;
	draw_square(data);
}
