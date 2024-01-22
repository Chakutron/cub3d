/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nearly_elems.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/22 15:21:28 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_nearly_elems(t_data *data, int x, int y)
{
	if (data->map.matrix[y][x] != '0' && data->map.matrix[y][x] != '1'
			&& data->map.matrix[y][x] != '2'
		&& data->map.matrix[y][x] != 'N' && data->map.matrix[y][x] != 'S'
		&& data->map.matrix[y][x] != 'E' && data->map.matrix[y][x] != 'W')
		return (1);
	return (0);
}
