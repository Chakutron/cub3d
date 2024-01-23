/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/23 14:41:28 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	blue_ceiling(t_data *data, char *tmp, int nbr)
{
	tmp = ft_calloc(1, 1);
	while (line[i + 2] != '\r')
	{
		tmp = ft_strcat2(tmp, line[i + 2]);
		i++;
	}
	nbr = ft_atoi(tmp);
	if (nbr == -42)
	{
		free(tmp);
		print_error(data, 2);
	}
	data->map.cell.b = nbr;
	free(tmp);
	data->map.info.c = 1;
	data->map.cell.color = create_trgb(0, data->map.cell.r,
			data->map.cell.g, data->map.cell.b);
	check_variables(data);
}

void	green_ceiling(t_data *data, char *tmp, int nbr)
{
	tmp = ft_calloc(1, 1);
	while (line[i + 2] != ',')
	{
		tmp = ft_strcat2(tmp, line[i + 2]);
		i++;
	}
	nbr = ft_atoi(tmp);
	if (nbr == -42)
	{
		free(tmp);
		print_error(data, 2);
	}
	data->map.cell.g = nbr;
	i++;
	free(tmp);
}

void	red_ceiling(t_data *data, char *tmp, int nbr)
{
	tmp = ft_calloc(1, 1);
	i = 0;
	while (line[i + 2] != ',')
	{
		tmp = ft_strcat2(tmp, line[i + 2]);
		i++;
	}
	nbr = ft_atoi(tmp);
	if (nbr == -42)
	{
		free(tmp);
		print_error(data, 2);
	}
	data->map.cell.r = nbr;
	i++;
	free(tmp);
}

void	ceiling_variable(t_data *data, char *line, char *tmp, int nbr)
{
	if (!data->map.info.c)
	{
		red_ceiling(data, tmp, nbr);
		green_ceiling(data, tmp, nbr);
		blue_ceiling(data, tmp, nbr);
		data->map.info.c = 1;
		data->map.cell.color = create_trgb(0, data->map.cell.r,
				data->map.cell.g, data->map.cell.b);
	}
	else
		print_error(data, 2);
}
