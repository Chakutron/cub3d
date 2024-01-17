/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces2map_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <mchiboub@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:30:45 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/17 16:40:17 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_spaces2map_2(t_data *data, int y, char **minimap)
{
	while (y < data->map.h)
	{
		free(data->map.matrix[y]);
		y++;
	}
	free(data->map.matrix);
	data->map.h += 2;
	data->map.matrix = minimap;
	y = 0;
	while (y < data->map.h)
	{
		while ((int)ft_strlen(data->map.matrix[y]) < data->map.w)
			data->map.matrix[y] = ft_strcat2(data->map.matrix[y], ' ');
		y++;
	}
}
