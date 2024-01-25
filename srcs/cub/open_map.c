/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <mchiboub@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:30:45 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 20:06:54 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `open_map` function is responsible for loading the map, adding spaces to
 * the map data, and checking the validity of the map. It prints status messages
 * during the process. If the map is invalid, it prints an error message.
 */

void	open_map(t_data *data)
{
	printf("- Loading map..\n\n");
	load_map(data);
	add_spaces2map(data);
	printf("\n- Checking map..\n\n");
	if (check_map(data))
		print_error(data, 6);
}
