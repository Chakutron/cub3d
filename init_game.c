/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/05 10:15:11 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_variables(t_data *data)
{
	data->endgame = 0;
	data->map.info.n = 0;
	data->map.info.s = 0;
	data->map.info.w = 0;
	data->map.info.e = 0;
	data->map.info.f = 0;
	data->map.info.c = 0;
	data->map.complete_info = 0;
	data->map.w = 0;
	data->map.h = 0;
}

void	load_images(t_data *data)
{
	(void)data;
	/*data->map.NO_texture = load_image(data->map.NO_file, data);
	data->map.SO_texture = load_image(data->map.SO_file, data);
	data->map.WE_texture = load_image(data->map.WE_file, data);
	data->map.EA_texture = load_image(data->map.EA_file, data);*/
}
