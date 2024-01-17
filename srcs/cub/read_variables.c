/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:23:22 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_variables(t_data *data, char *line)
{
	char	*tmp;
	int		i;
	int		nbr;

	if (strncmp(line, "NO ", 3) == 0)
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
	else if (strncmp(line, "SO ", 3) == 0)
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
	else if (strncmp(line, "WE ", 3) == 0)
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
	else if (strncmp(line, "EA ", 3) == 0)
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
	else if (strncmp(line, "F ", 2) == 0)
	{
		if (!data->map.info.f)
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
			data->map.floor.r = nbr;
			i++;
			free(tmp);
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
			data->map.floor.g = nbr;
			i++;
			free(tmp);
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
			data->map.floor.b = nbr;
			free(tmp);
			data->map.info.f = 1;
			data->map.floor.color = create_trgb(0, data->map.floor.r,
					data->map.floor.g, data->map.floor.b);
			check_variables(data);
		}
		else
			print_error(data, 2);
	}
	else if (strncmp(line, "C ", 2) == 0)
	{
		if (!data->map.info.c)
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
		else
			print_error(data, 2);
	}
}