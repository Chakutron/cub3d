/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surround.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:43:23 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `check_surround` function verifies if the element at the specified
 * position (x, y) in the map matrix is surrounded by valid map elements. It
 * checks if the element is at the map boundaries or if any adjacent elements
 * are invalid using the `check_nearly_elems` function. It returns 1 if any
 * surrounding element is invalid, indicating an invalid map position,
 * otherwise, it returns 0.
 */

int	check_surround(t_data *data, int x, int y)
{
	if (x == 0 || y == 0)
		return (1);
	else if (x == data->map.w - 1 || y == data->map.h - 1)
		return (1);
	if (check_nearly_elems(data, x - 1, y - 1))
		return (1);
	if (check_nearly_elems(data, x, y - 1))
		return (1);
	if (check_nearly_elems(data, x + 1, y - 1))
		return (1);
	if (check_nearly_elems(data, x - 1, y))
		return (1);
	if (check_nearly_elems(data, x + 1, y))
		return (1);
	if (check_nearly_elems(data, x - 1, y + 1))
		return (1);
	if (check_nearly_elems(data, x, y + 1))
		return (1);
	if (check_nearly_elems(data, x + 1, y + 1))
		return (1);
	return (0);
}
