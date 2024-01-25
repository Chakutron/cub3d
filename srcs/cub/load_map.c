/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/18 16:03:51 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `load_map` function reads the map file line by line, extracts relevant
 * information such as map size and matrix, and stores it in the `data`
 * structure. It then prints out the variables loaded from the map file.
 */

void	load_map(t_data *data)
{
	data->fd = open(data->map.filename, O_RDONLY);
	if (data->fd == -1)
		print_error(data, 4);
	data->map.mapstart = 0;
	read_line_by_line(data);
	close(data->fd);
	if (!data->map.complete_info)
		print_error(data, 2);
	printf("- Map starting at line: %i\n\n", data->map.mapstart);
	if (!data->map.h || !data->map.w)
		print_error(data, 6);
	data->map.matrix = malloc(sizeof(char *) * (data->map.h));
	data->fd = open(data->map.filename, O_RDONLY);
	free_elements_store_map(data);
	data->line = get_next_line(data->fd);
	finish_gnl(data);
	print_variables(data);
}
