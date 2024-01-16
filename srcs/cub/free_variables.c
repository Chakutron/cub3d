/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:48:59 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		free(data->map.NO_file);
	if (data->map.info.s)
		free(data->map.SO_file);
	if (data->map.info.w)
		free(data->map.WE_file);
	if (data->map.info.e)
		free(data->map.EA_file);
}
