/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/23 14:21:32 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	east_variable(t_data *data)
{
	if (!data->map.info.e)
	{
		data->map.EA_file = ft_strdup2(&line[3]);
		if (ft_strlen(data->map.EA_file) > 0)
			clean_return_line(data->map.EA_file);
		data->map.info.e = 1;
		data->fd2 = open(data->map.EA_file, O_RDONLY);
		if (data->fd2 == -1)
			print_error(data, 5);
		close(data->fd2);
		check_variables(data);
	}
	else
		print_error(data, 2);
}

void	west_variable(t_data *data)
{
	if (!data->map.info.w)
	{
		data->map.WE_file = ft_strdup2(&line[3]);
		if (ft_strlen(data->map.WE_file) > 0)
			clean_return_line(data->map.WE_file);
		data->map.info.w = 1;
		data->fd2 = open(data->map.WE_file, O_RDONLY);
		if (data->fd2 == -1)
			print_error(data, 5);
		close(data->fd2);
		check_variables(data);
	}
	else
		print_error(data, 2);
}

void	south_variable(t_data *data)
{
	if (!data->map.info.s)
	{
		data->map.SO_file = ft_strdup2(&line[3]);
		if (ft_strlen(data->map.SO_file) > 0)
			clean_return_line(data->map.SO_file);
		data->map.info.s = 1;
		data->fd2 = open(data->map.SO_file, O_RDONLY);
		if (data->fd2 == -1)
			print_error(data, 5);
		close(data->fd2);
		check_variables(data);
	}
	else
		print_error(data, 2);
}

void	north_variable(t__data *data)
{
	if (!data->map.info.n)
	{
		data->map.NO_file = ft_strdup2(&line[3]);
		if (ft_strlen(data->map.NO_file) > 0)
			clean_return_line(data->map.NO_file);
		data->map.info.n = 1;
		data->fd2 = open(data->map.NO_file, O_RDONLY);
		if (data->fd2 == -1)
			print_error(data, 5);
		close(data->fd2);
		check_variables(data);
	}
	else
		print_error(data, 2);
}

void	read_variables(t_data *data, char *line)
{
	char	*tmp;
	int		nbr;

	if (strncmp(line, "NO ", 3) == 0)
		north_variable(data, line);
	else if (strncmp(line, "SO ", 3) == 0)
		south_variable(data, line);
	else if (strncmp(line, "WE ", 3) == 0)
		west_variable(data, line);
	else if (strncmp(line, "EA ", 3) == 0)
		east_variable(data, line);
	else if (strncmp(line, "F ", 2) == 0)
		floor_variable(data, line, tmp, nbr);
	else if (strncmp(line, "C ", 2) == 0)
		ceiling_variable(data, line, tmp, nbr);
}
