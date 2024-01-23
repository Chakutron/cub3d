/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/23 16:07:25 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	blue_floor(t_data *data, char *line, char *tmp, int nbr)
{
	tmp = ft_calloc(1, 1);
	while (line[data->map.i + 2] != '\r')
	{
		tmp = ft_strcat2(tmp, line[data->map.i + 2]);
		data->map.i++;
	}
	nbr = ft_atoi(tmp);
	if (nbr == -42)
	{
		free(tmp);
		print_error(data, 2);
	}
	data->map.floor.b = nbr;
	free(tmp);
}

void	green_floor(t_data *data, char *line, char *tmp, int nbr)
{
	tmp = ft_calloc(1, 1);
	while (line[data->map.i + 2] != ',')
	{
		tmp = ft_strcat2(tmp, line[data->map.i + 2]);
		data->map.i++;
	}
	nbr = ft_atoi(tmp);
	if (nbr == -42)
	{
		free(tmp);
		print_error(data, 2);
	}
	data->map.floor.g = nbr;
	data->map.i++;
	free(tmp);
}

void	red_floor(t_data *data, char *line, char *tmp, int nbr)
{
	data->map.i = 0;
	while (line[data->map.i + 2] != ',')
	{
		tmp = ft_strcat2(tmp, line[data->map.i + 2]);
		data->map.i++;
	}
	nbr = ft_atoi(tmp);
	if (nbr == -42)
	{
		free(tmp);
		print_error(data, 2);
	}
	data->map.floor.r = nbr;
	data->map.i++;
	free(tmp);
}

void	floor_variable(t_data *data, char *line, char *tmp, int nbr)
{
	if (!data->map.info.f)
	{
		red_floor(data, line, tmp, nbr);
		green_floor(data, line, tmp, nbr);
		blue_floor(data, line, tmp, nbr);
		data->map.info.f = 1;
		data->map.floor.color = create_trgb(0, data->map.floor.r,
				data->map.floor.g, data->map.floor.b);
		check_variables(data);
	}
	else
		print_error(data, 2);
}
