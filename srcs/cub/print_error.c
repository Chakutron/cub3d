/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/26 16:16:25 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `print_error` function displays error messages related to different types
 * of errors encountered during map parsing and rendering. It terminates the
 * program after printing the error message.
 */

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
	else if (error == 3 || error == 4)
		(void)data;
	else
		finish_gnl(data);
	if (error != 3 && error != 4)
		free_variables(data);
	exit(1);
}
