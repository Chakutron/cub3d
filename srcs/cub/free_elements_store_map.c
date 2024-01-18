/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements_store_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/18 16:03:36 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_elements_store_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.mapstart)
	{
		data->line = get_next_line(data->fd);
		free(data->line);
		i++;
	}
	i = 0;
	while (i < data->map.h)
	{
		data->map.matrix[i] = get_next_line(data->fd);
		clean_return_line(data->map.matrix[i]);
		i++;
	}
}
