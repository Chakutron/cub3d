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

void	blue_ceiling(t_data *data, char *line, char *tmp, int nbr)
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
	data->map.cell.b = nbr;
	free(tmp);
}

void	green_ceiling(t_data *data, char *line, char *tmp, int nbr)
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
	data->map.cell.g = nbr;
	data->map.i++;
	free(tmp);
}

void	red_ceiling(t_data *data, char *line, char *tmp, int nbr)
{
	tmp = ft_calloc(1, 1);
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
	data->map.cell.r = nbr;
	data->map.i++;
	free(tmp);
}

void	ceiling_variable(t_data *data, char *line, char *tmp, int nbr)
{
	if (!data->map.info.c)
	{
		red_ceiling(data, line, tmp, nbr);
		green_ceiling(data, line, tmp, nbr);
		blue_ceiling(data, line, tmp, nbr);
		data->map.info.c = 1;
		data->map.cell.color = create_trgb(0, data->map.cell.r,
				data->map.cell.g, data->map.cell.b);
		check_variables(data);
	}
	else
		print_error(data, 2);
}
