 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/05 10:53:34 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_extension(t_data *data)
{
	int	i;

	i = ft_strlen(data->map.filename) - 4;
	if (data->map.filename[i] == '.' && data->map.filename[i + 1] == 'c'
		&& data->map.filename[i + 2] == 'u' && data->map.filename[i + 3] == 'b')
		return (0);
	return (1);
}

void	finish_gnl(t_data *data)
{
	while (data->line != NULL)
	{
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	close(data->fd);
}

void	write_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	print_error(t_data *data, int error)
{
	write_error("\e[0;31m* ERROR found in map: ");
	write_error(data->map.filename);
	write_error("\n");
	if (error == 1)
		write_error("  Error when generating display/window!\n");
	else if (error == 2)
		write_error("  Wrong variable format!\n");
	else if (error == 3)
		write_error("  Wrong extension file!\n");
	else if (error == 4)
		write_error("  Cant open the file!\n");
	else if (error == 5)
		write_error("  Cant open the texture file!\n");
	else if (error == 6)
		write_error("  Wrong map format!\n");
	write_error("\e[0m");
	if (error == 1)
		close_game(data);
	else
	finish_gnl(data);
	free_variables(data);
	exit(1);
}

void	check_variables(t_data *data)
{
	int	info;

	info = 0;
	info += data->map.info.n;
	info += data->map.info.s;
	info += data->map.info.w;
	info += data->map.info.e;
	info += data->map.info.f;
	info += data->map.info.c;
	if (info == 6)
		data->map.complete_info = 1;
	else
		data->map.complete_info = 0;
}

void	clean_return_line(char *str)
{
	if (str[ft_strlen(str) - 1] == '\n')
	{
		if (str[ft_strlen(str) - 2] == '\r')
			str[ft_strlen(str) - 2] = '\0';
		else
			str[ft_strlen(str) - 1] = '\0';
	}
}

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
				//data->map.NO_file[ft_strlen(data->map.NO_file) - 1] = '\0';
			data->map.info.n = 1;
			/*data->fd = open(data->map.NO_file, O_RDONLY);
			if (data->fd == -1)
				print_error(data, 5);
			close(data->fd);*/
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
				//data->map.SO_file[ft_strlen(data->map.SO_file) - 1] = '\0';
			data->map.info.s = 1;
			/*data->fd = open(data->map.SO_file, O_RDONLY);
			if (data->fd == -1)
				print_error(data, 5);
			close(data->fd);*/
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
				//data->map.WE_file[ft_strlen(data->map.WE_file) - 1] = '\0';
			data->map.info.w = 1;
			/*data->fd = open(data->map.WE_file, O_RDONLY);
			if (data->fd == -1)
				print_error(data, 5);
			close(data->fd);*/
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
				//data->map.EA_file[ft_strlen(data->map.EA_file) - 1] = '\0';
			data->map.info.e = 1;
			/*data->fd = open(data->map.EA_file, O_RDONLY);
			if (data->fd == -1)
				print_error(data, 5);
			close(data->fd);*/
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
			data->map.floor.color = create_trgb(0, data->map.floor.r, data->map.floor.g, data->map.floor.b);
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
			data->map.cell.color = create_trgb(0, data->map.cell.r, data->map.cell.g, data->map.cell.b);
			check_variables(data);
		}
		else
			print_error(data, 2);
	}
}

void print_variables(t_data *data)
{
	int	i;
	
	printf("NO file = %s\n", data->map.NO_file);
	printf("SO file = %s\n", data->map.SO_file);
	printf("WE file = %s\n", data->map.WE_file);
	printf("EA file = %s\n", data->map.EA_file);
	printf("Floor color = 0x%08X (%i, %i, %i)\n", data->map.floor.color, data->map.floor.r, data->map.floor.g, data->map.floor.b);
	printf("Cell color = 0x%08X (%i, %i, %i)\n", data->map.cell.color, data->map.cell.r, data->map.cell.g, data->map.cell.b);
	printf("Map dimension = (%i x %i)\n\n", data->map.h, data->map.w);
	i = 0;
	while (i < data->map.h)
	{
		printf("%s\n", data->map.matrix[i]);
		i++;
	}
}

void	load_map(t_data *data)
{
	int		mapstart;
	int		i;

	data->fd = open(data->map.filename, O_RDONLY);
	if (data->fd == -1)
		print_error(data, 4);
	mapstart = 0;
	while (1)
	{
		data->line = get_next_line(data->fd);
		if (data->line == NULL)
			break ;
		if (data->line[0] != '\r' && data->line[0] != '\n')
		{
			if (data->map.complete_info)
			{
				clean_return_line(data->line);
				if (((int)ft_strlen(data->line)) > data->map.w)
					data->map.w = ft_strlen(data->line);
				data->map.h++;
			}
			else
			{
				read_variables(data, data->line);
				mapstart++;
			}
		}
		else
			mapstart++;
		free(data->line);
	}
	close(data->fd);
	if (!data->map.complete_info)
		print_error(data, 2);
	printf("- Map starting at line: %i\n\n", mapstart);
	if (!data->map.h || !data->map.w)
		print_error(data, 6);
	data->map.matrix = malloc(sizeof(char *) * (data->map.h));
	data->fd = open(data->map.filename, O_RDONLY);
	i = 0;
	while (i < mapstart)
	{
		data->line = get_next_line(data->fd);
		free(data->line);
		i++;
	}
	i = 0;
	while (i < data->map.h)
	{
		data->map.matrix[i] = get_next_line(data->fd);
		clean_return_line(data->map.matrix[i]);
		i++;
	}
	data->line = get_next_line(data->fd);
	finish_gnl(data);
	print_variables(data);
}