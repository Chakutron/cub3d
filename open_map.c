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
}
