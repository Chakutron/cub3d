/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/26 15:55:39 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `free_variables` function deallocates memory for map elements and texture
 * files stored in the `data` structure. It iterates through the map matrix and
 * frees memory for each row and then for the matrix itself. Additionally, it
 * frees memory for loaded texture files if they exist.
 */

void	free_variables(t_data *data)
{
	int	i;

	if (data->map.h && data->map.w)
	{
		i = 0;
		while (i < data->map.h)
		{
			free(data->map.matrix[i]);
			i++;
		}
		free(data->map.matrix);
	}
	if (data->map.info.n)
		free(data->map.no_file);
	if (data->map.info.s)
		free(data->map.so_file);
	if (data->map.info.w)
		free(data->map.we_file);
	if (data->map.info.e)
		free(data->map.ea_file);
}
