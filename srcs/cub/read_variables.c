/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/26 16:00:46 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `east_variable` function sets the east texture file path and checks if
 * it's already been set. If not, it duplicates the path, validates it, and
 * updates the variable. Otherwise, it triggers an error due to a duplicate
 * variable assignment.
 */

void	east_variable(t_data *data, char *line)
{
	if (!data->map.info.e)
	{
		data->map.ea_file = ft_strdup2(&line[3]);
		if (ft_strlen(data->map.ea_file) > 0)
			clean_return_line(data->map.ea_file);
		data->map.info.e = 1;
		data->fd2 = open(data->map.ea_file, O_RDONLY);
		if (data->fd2 == -1)
			print_error(data, 5);
		close(data->fd2);
		check_variables(data);
	}
	else
		print_error(data, 2);
}

/*
 * The `west_variable` function sets the west texture file path and checks if
 * it's already been set. If not, it duplicates the path, validates it, and
 * updates the variable. Otherwise, it triggers an error due to a duplicate
 * variable assignment.
 */

void	west_variable(t_data *data, char *line)
{
	if (!data->map.info.w)
	{
		data->map.we_file = ft_strdup2(&line[3]);
		if (ft_strlen(data->map.we_file) > 0)
			clean_return_line(data->map.we_file);
		data->map.info.w = 1;
		data->fd2 = open(data->map.we_file, O_RDONLY);
		if (data->fd2 == -1)
			print_error(data, 5);
		close(data->fd2);
		check_variables(data);
	}
	else
		print_error(data, 2);
}

/*
 * The `south_variable` function sets the south texture file path and checks if
 * it's already been set. If not, it duplicates the path, validates it, and
 * updates the variable. Otherwise, it triggers an error due to a duplicate
 * variable assignment.
 */

void	south_variable(t_data *data, char *line)
{
	if (!data->map.info.s)
	{
		data->map.so_file = ft_strdup2(&line[3]);
		if (ft_strlen(data->map.so_file) > 0)
			clean_return_line(data->map.so_file);
		data->map.info.s = 1;
		data->fd2 = open(data->map.so_file, O_RDONLY);
		if (data->fd2 == -1)
			print_error(data, 5);
		close(data->fd2);
		check_variables(data);
	}
	else
		print_error(data, 2);
}

/*
 * The `north_variable` function sets the north texture file path and checks if
 * it's already been set. If not, it duplicates the path, validates it, and
 * updates the variable. Otherwise, it triggers an error due to a duplicate
 * variable assignment.
 */

void	north_variable(t_data *data, char *line)
{
	if (!data->map.info.n)
	{
		data->map.no_file = ft_strdup2(&line[3]);
		if (ft_strlen(data->map.no_file) > 0)
			clean_return_line(data->map.no_file);
		data->map.info.n = 1;
		data->fd2 = open(data->map.no_file, O_RDONLY);
		if (data->fd2 == -1)
			print_error(data, 5);
		close(data->fd2);
		check_variables(data);
	}
	else
		print_error(data, 2);
}

/*
 * The `read_variables` function processes the given line to extract and set
 * various map-related variables, such as textures, floor color,
 * and ceiling color.
 */

void	read_variables(t_data *data, char *line)
{
	int		nbr;

	nbr = 0;
	if (strncmp(line, "NO ", 3) == 0)
		north_variable(data, line);
	else if (strncmp(line, "SO ", 3) == 0)
		south_variable(data, line);
	else if (strncmp(line, "WE ", 3) == 0)
		west_variable(data, line);
	else if (strncmp(line, "EA ", 3) == 0)
		east_variable(data, line);
	else if (strncmp(line, "F ", 2) == 0)
		floor_variable(data, line, nbr);
	else if (strncmp(line, "C ", 2) == 0)
		ceiling_variable(data, line, nbr);
}
