/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/18 15:32:07 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_variables(t_data *data)
{
	data->player.nbr = 0;
	data->map.info.n = 0;
	data->map.info.s = 0;
	data->map.info.w = 0;
	data->map.info.e = 0;
	data->map.info.f = 0;
	data->map.info.c = 0;
	data->map.complete_info = 0;
	data->map.w = 0;
	data->map.h = 0;
	data->key.w = 0;
	data->key.s = 0;
	data->key.a = 0;
	data->key.d = 0;
	data->endgame = 0;
	data->rc_dist_offset = (WIDTH / 2) / 30;
	data->player.speed = 0.05;
	data->ratio = 5;
	data->cursor_x = 450;
	data->player.walk.index = 0;
	data->rick.index = 0;
	data->timer = 0.0;
}
