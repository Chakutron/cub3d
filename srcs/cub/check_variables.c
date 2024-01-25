/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:16:41 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `check_variables` function verifies if all required variables for the
 * map are set. It increments a counter for each required variable found. If
 * all required variables are set (indicated by the counter reaching 6), it
 * marks the map's information as complete; otherwise, it marks it
 * as incomplete.
 */

void	check_variables(t_data *data)
{
	int	info;

	info = 0;
	info += data->map.info.n;
	info += data->map.info.s;
	info += data->map.info.w;
	info += data->map.info.e;
	info += data->map.info.f;
	info += data->map.info.c;
	if (info == 6)
		data->map.complete_info = 1;
	else
		data->map.complete_info = 0;
}
