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

void	write_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	print_error(t_data *data, int error)
{
	write_error("\033[0;31m* ERROR found in map: ");
	write_error(data->map.filename);
	write_error("\n");
	if (error == 1 || error == 2)
		write_error("  Wrong format!\n");
	else if (error == 3)
		write_error("  Wrong extension file!\n");
	else if (error == 4)
		write_error("  Cant open the file!\n");
	exit (0);
}

void	read_map(t_data *data, char *line, int x, int y)
{
	if (line[0] == '\0' || line[0] == '\n')
		print_error(data, 2);
	data->map.matrix[x][y] = line[x];
	printf("%c", line[x]);
	if (line[x] == 'N')
	{
		data->player.x = x;
		data->player.y = y;
		data->player.angle = 90;
	}
	else if (line[x] == 'S')
	{
		data->player.x = x;
		data->player.y = y;
		data->player.angle = 270;
	}
	else if (line[x] == 'W')
	{
		data->player.x = x;
		data->player.y = y;
		data->player.angle = 180;
	}
	else if (line[x] == 'E')
	{
		data->player.x = x;
		data->player.y = y;
		data->player.angle = 0;
	}
	else if (line[x] != '1' && line[x] != '0' && line[x] != '\n')
		print_error(data, 1);
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

void	read_variables(t_data *data, char *line)
{
	char	*tmp;
	int		i;

	if (strncmp(line, "NO ", 3) == 0)
	{
		if (!data->map.info.n)
		{
			data->map.NO_file = ft_strdup2(&line[3]);
			data->map.info.n = 1;
			check_variables(data);
		}
		else
			print_error(data, 1);
	}
	else if (strncmp(line, "SO ", 3) == 0)
	{
		if (!data->map.info.s)
		{
			data->map.SO_file = ft_strdup2(&line[3]);
			data->map.info.s = 1;
			check_variables(data);
		}
		else
			print_error(data, 1);
	}
	else if (strncmp(line, "WE ", 3) == 0)
	{
		if (!data->map.info.w)
		{
			data->map.WE_file = ft_strdup2(&line[3]);
			data->map.info.w = 1;
			check_variables(data);
		}
		else
			print_error(data, 1);
	}
	else if (strncmp(line, "EA ", 3) == 0)
	{
		if (!data->map.info.e)
		{
			data->map.EA_file = ft_strdup2(&line[3]);
			data->map.info.e = 1;
			check_variables(data);
		}
		else
			print_error(data, 1);
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
			data->map.floor.r = ft_atoi(tmp);
			i++;
			free(tmp);
			tmp = ft_calloc(1, 1);
			while (line[i + 2] != ',')
			{
				tmp = ft_strcat2(tmp, line[i + 2]);
				i++;
			}
			data->map.floor.g = ft_atoi(tmp);
			i++;
			free(tmp);
			tmp = ft_calloc(1, 1);
			while (line[i + 2] != '\r')
			{
				tmp = ft_strcat2(tmp, line[i + 2]);
				i++;
			}
			data->map.floor.b = ft_atoi(tmp);
			free(tmp);			
			data->map.info.f = 1;
			check_variables(data);
		}
		else
			print_error(data, 1);
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
			data->map.cell.r = ft_atoi(tmp);
			i++;
			free(tmp);
			tmp = ft_calloc(1, 1);
			while (line[i + 2] != ',')
			{
				tmp = ft_strcat2(tmp, line[i + 2]);
				i++;
			}
			data->map.cell.g = ft_atoi(tmp);
			i++;
			free(tmp);
			tmp = ft_calloc(1, 1);
			while (line[i + 2] != '\r')
			{
				tmp = ft_strcat2(tmp, line[i + 2]);
				i++;
			}
			data->map.cell.b = ft_atoi(tmp);
			free(tmp);			
			data->map.info.c = 1;
			check_variables(data);
		}
		else
			print_error(data, 1);
	}
}

void print_variables(t_data *data)
{
	printf("NO file = %s\n", data->map.NO_file);
	printf("SO file = %s\n", data->map.SO_file);
	printf("WE file = %s\n", data->map.WE_file);
	printf("EA file = %s\n", data->map.EA_file);
	printf("Floor color = (%i, %i, %i)\n", data->map.floor.r, data->map.floor.g, data->map.floor.b);
	printf("Cell color = (%i, %i, %i)\n", data->map.cell.r, data->map.cell.g, data->map.cell.b);
}

void	load_map(t_data *data)
{
	int		fd;
	char	*line;
	int		x;
	int		y;
	int		mapstart;

	fd = open(data->map.filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(data, 4);
		exit(1);
	}
	mapstart = 0;
	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		mapstart++;
		if (line == NULL)
			break ;
		if (line[0] != '\r')
		{
			if (data->map.complete_info)
			{
				x = 0;
				y = 0;
				print_variables(data);
				if (line[0] != '\r')
					break ;
				//break ;
				/*x = 0;
				while (line[x])
				{
					read_map(data, line, x, y);
					x++;
				}
				y++;*/
			}
			else
				read_variables(data, line);
		}
		free(line);
	}
	printf("\nMap starting at line: %i\n", mapstart);
	data->map.w = x;
	data->map.h = y;
	close(fd);
}
