/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/12/07 13:40:47 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_path2(t_data *data, int x, int y, char c)
{
	/*if ((x == 0 || x == data->map_x - 1) && c != '1')
	{
		printf("\033[0;31m%c\033[0m", c);
		return (-1);
	}
	else if ((y == 0 || y == data->map_y - 1) && c != '1')
	{
		printf("\033[0;31m%c\033[0m", c);
		return (-1);
	}
	else if (c == 'P' || c == 'C' || c == 'E')
	{
		printf("\033[0;31m%c\033[0m", c);
		return (-1);
	}
	else if (c == '*')
		printf("\033[0;33m%c\033[0m", c);
	else
		printf("%c", c);
	if (c == 'P' || c == 'C' || c == 'E')
		return (-1);
	return (0);*/
	(void)data;
	(void)x;
	(void)y;
	(void)c;
	return (0);
}

int	check_path(t_data *data)
{
	/*int		x;
	int		y;
	char	c;
	int		path;

	path = 0;
	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			c = data->map2[x][y];
			if (check_path2(data, x, y, c) == -1)
				path = -1;
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
	return (path);*/
	(void)data;
	return (0);
}

void	make_path(t_data *data, int x, int y)
{
	/*if (x >= 0 && x < data->map_x && y >= 0 && y < data->map_y)
	{
		if (data->map2[x][y] != '1' && data->map2[x][y] != '*')
		{
			data->map2[x][y] = '*';
			make_path(data, x + 1, y);
			make_path(data, x - 1, y);
			make_path(data, x, y + 1);
			make_path(data, x, y - 1);
		}
	}*/
	(void)data;
	(void)x;
	(void)y;
}

void	copy_map(t_data *data)
{
	/*int	x;
	int	y;

	printf("\n- Checking map..\n\n");
	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			data->map2[x][y] = data->map[x][y];
			x++;
		}
		y++;
	}*/
	(void)data;
}

int	check_map(t_data *data)
{
	copy_map(data);
	make_path(data, data->player.x, data->player.y);
	return (check_path(data));
}
