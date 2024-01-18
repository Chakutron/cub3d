/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/18 18:05:57 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	empty_space(int x, int y, t_data *data)
{
	if (check_surround(data, x, y))
	{
		printf(BLACK REDB "%c " NC, data->map.matrix[y][x]);
		data->map.error_found = 1;
	}
	else
		printf(YELLOWB "  " NC);
}
