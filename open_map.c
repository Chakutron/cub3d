/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <mchiboub@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:30:45 by mchiboub          #+#    #+#             */
/*   Updated: 2023/12/07 13:38:15 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_map(t_data *data)
{
	printf("- Loading map..\n\n");
	load_map(data);
	/*if (data->player != 1 || data->exits != 1 || data->total_coins == 0)
		print_error(data, 0);
	if (check_map(data) == -1)
		printf("\033[0;31m* ERROR found in map: %s\n\n", data->file);
	else
	{
		printf("- Map loaded! (%ix%i)\n\n", data->map_x, data->map_y);
		load_images(data);
		data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
				WINDOW_HEIGHT, "SO_LONG [Intro] by Chaku");
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->image[16].ptr, WINDOW_WIDTH / 2 - data->image[16].w / 2,
			WINDOW_HEIGHT / 2 - data->image[16].h / 2);
		mlx_loop_hook(data->mlx_ptr, &title_render, data);
		mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &title_keypress, data);
		printf("\nPress the SPACE key to continue..\n\n");
		start_game(data);
	}*/
}
