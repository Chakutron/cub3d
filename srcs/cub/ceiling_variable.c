/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/23 16:10:56 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `blue_ceiling` function extracts and sets the blue component of the
 * ceiling color. It iterates through the input line, parsing characters until
 * encountering a comma. It converts the parsed substring to an integer and
 * assigns it to the blue component of the ceiling color. If the conversion
 * fails, it prints an error message. 
 */

void	blue_ceiling(t_data *data, char *line, int nbr)
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
	data->map.cell.b = nbr;
	free(data->tmp.tmp);
}

/*
 * The `green_ceiling` function extracts and sets the green component of the
 * ceiling color. It iterates through the input line, parsing characters until
 * encountering a comma. It converts the parsed substring to an integer and
 * assigns it to the green component of the ceiling color. If the conversion
 * fails, it prints an error message.
 */

void	green_ceiling(t_data *data, char *line, int nbr)
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
	data->map.cell.g = nbr;
	data->map.i++;
	free(data->tmp.tmp);
}

/*
 * The `red_ceiling` function extracts and sets the red component of the
 * ceiling color. It iterates through the input line, parsing characters until
 * encountering a comma. It converts the parsed substring to an integer and
 * assigns it to the red component of the ceiling color. If the conversion
 * fails, it prints an error message. 
 */

void	red_ceiling(t_data *data, char *line, int nbr)
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
	data->map.cell.r = nbr;
	data->map.i++;
	free(data->tmp.tmp);
}

/* 
 * The `ceiling_variable` function sets the color of the ceiling in the map if
 * it hasn't been set yet. It parses the RGB components from the input line and
 * assigns them to the ceiling color. If the color has already been set, it
 * prints an error message.
 */

void	ceiling_variable(t_data *data, char *line, int nbr)
{
	if (!data->map.info.c)
	{
		red_ceiling(data, line, nbr);
		green_ceiling(data, line, nbr);
		blue_ceiling(data, line, nbr);
		data->map.info.c = 1;
		data->map.cell.color = create_trgb(0, data->map.cell.r,
				data->map.cell.g, data->map.cell.b);
		check_variables(data);
	}
	else
		print_error(data, 2);
}
