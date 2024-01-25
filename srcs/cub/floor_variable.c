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

/*
 * The `blue_floor` function extracts the blue component of the floor color from
 * the configuration file. It parses the value until encountering a comma,
 * converts it to an integer, and assigns it to `data->map.floor.b`. If the
 * conversion fails or encounters an invalid value, it triggers an error message.
 */

void	blue_floor(t_data *data, char *line, int nbr)
{
	data->tmp.tmp = ft_calloc(1, 1);
	while (line[data->map.i + 2] != '\r')
	{
		data->tmp.tmp = ft_strcat2(data->tmp.tmp, line[data->map.i + 2]);
		data->map.i++;
	}
	nbr = ft_atoi(data->tmp.tmp);
	if (nbr == -42)
	{
		free(data->tmp.tmp);
		print_error(data, 2);
	}
	data->map.floor.b = nbr;
	free(data->tmp.tmp);
}

/*
 * The `green_floor` function extracts the green component of the floor color
 * from the configuration file. It parses the value until encountering a comma,
 * converts it to an integer, and assigns it to `data->map.floor.g`. If the
 * conversion fails or encounters an invalid value, it triggers an error message.
 */

void	green_floor(t_data *data, char *line, int nbr)
{
	data->tmp.tmp = ft_calloc(1, 1);
	while (line[data->map.i + 2] != ',')
	{
		data->tmp.tmp = ft_strcat2(data->tmp.tmp, line[data->map.i + 2]);
		data->map.i++;
	}
	nbr = ft_atoi(data->tmp.tmp);
	if (nbr == -42)
	{
		free(data->tmp.tmp);
		print_error(data, 2);
	}
	data->map.floor.g = nbr;
	data->map.i++;
	free(data->tmp.tmp);
}

/*
 * The `red_floor` function extracts the red component of the floor color from
 * the configuration file. It parses the value until encountering a comma,
 * converts it to an integer, and assigns it to `data->map.floor.r`. If the
 * conversion fails or encounters an invalid value, it triggers an error message.
 */

void	red_floor(t_data *data, char *line, int nbr)
{
	data->tmp.tmp = ft_calloc(1, 1);
	data->map.i = 0;
	while (line[data->map.i + 2] != ',')
	{
		data->tmp.tmp = ft_strcat2(data->tmp.tmp, line[data->map.i + 2]);
		data->map.i++;
	}
	nbr = ft_atoi(data->tmp.tmp);
	if (nbr == -42)
	{
		free(data->tmp.tmp);
		print_error(data, 2);
	}
	data->map.floor.r = nbr;
	data->map.i++;
	free(data->tmp.tmp);
}

/*
 * The `floor_variable` function parses and sets the floor color components
 * from the configuration file. It extracts the RGB values from the line,
 * calculates the final color using `create_trgb`, and updates the `data`
 * structure. If the floor color info is already set, it prints an error.
 */

void	floor_variable(t_data *data, char *line, int nbr)
{
	if (!data->map.info.f)
	{
		red_floor(data, line, nbr);
		green_floor(data, line, nbr);
		blue_floor(data, line, nbr);
		data->map.info.f = 1;
		data->map.floor.color = create_trgb(0, data->map.floor.r,
				data->map.floor.g, data->map.floor.b);
		check_variables(data);
	}
	else
		print_error(data, 2);
}
