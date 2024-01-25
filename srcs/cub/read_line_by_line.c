/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line_by_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/18 15:37:11 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The function `read_line_by_line` iterates through each line, processing it to
 * determine the map's dimensions or read variables, terminating upon reaching
 * the end of the file or encountering an error.
 */

void	read_line_by_line(t_data *data)
{
	while (1)
	{
		data->line = get_next_line(data->fd);
		if (data->line == NULL)
			break ;
		if (data->line[0] != '\r' && data->line[0] != '\n')
		{
			if (data->map.complete_info)
			{
				clean_return_line(data->line);
				if (((int)ft_strlen(data->line)) > data->map.w)
					data->map.w = ft_strlen(data->line);
				data->map.h++;
			}
			else
			{
				read_variables(data, data->line);
				data->map.mapstart++;
			}
		}
		else
			data->map.mapstart++;
		free(data->line);
	}
}
