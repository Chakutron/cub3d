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

void	add_spaces2map(t_data *data)
{
	int		y;
	char	**minimap;

	y = 0;
	while (y < data->map.h)
	{
		data->map.matrix[y] = ft_strjoin3(" ", data->map.matrix[y]);
		data->map.matrix[y] = ft_strcat2(data->map.matrix[y], ' ');
		y++;
	}
	data->map.w += 2;
	minimap = malloc(sizeof(char *) * (data->map.h + 2));
	minimap[0] = ft_strdup2(" ");
	y = 0;
	while (y < data->map.h)
	{
		minimap[y + 1] = ft_strdup2(data->map.matrix[y]);
		y++;
	}
	minimap[y + 1] = ft_strdup2(" ");
	y = 0;
	while (y < data->map.h)
	{
		free(data->map.matrix[y]);
		y++;
	}
	free(data->map.matrix);
	data->map.h += 2;
	data->map.matrix = minimap;
	y = 0;
	while (y < data->map.h)
	{
		while ((int)ft_strlen(data->map.matrix[y]) < data->map.w)
			data->map.matrix[y] = ft_strcat2(data->map.matrix[y], ' ');
		y++;
	}
}

void	open_map(t_data *data)
{
	printf("- Loading map..\n\n");
	load_map(data);
	add_spaces2map(data);
	printf("\n- Checking map..\n\n");
	if (check_map(data))
		print_error(data, 6);
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
