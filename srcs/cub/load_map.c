/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:28:27 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_map(t_data *data)
{
	int		mapstart;
	int		i;

	data->fd = open(data->map.filename, O_RDONLY);
	if (data->fd == -1)
		print_error(data, 4);
	mapstart = 0;
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
				mapstart++;
			}
		}
		else
			mapstart++;
		free(data->line);
	}
	close(data->fd);
	if (!data->map.complete_info)
		print_error(data, 2);
	printf("- Map starting at line: %i\n\n", mapstart);
	if (!data->map.h || !data->map.w)
		print_error(data, 6);
	data->map.matrix = malloc(sizeof(char *) * (data->map.h));
	data->fd = open(data->map.filename, O_RDONLY);
	i = 0;
	while (i < mapstart)
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
	data->line = get_next_line(data->fd);
	finish_gnl(data);
	print_variables(data);
}
