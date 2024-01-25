/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <mchiboub@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:30:45 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:03:27 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* 
 * The `main` function is the entry point of the program. It checks if the
 * correct number of command-line arguments is provided. If so, it initializes
 * the `data` structure, sets the map filename, checks the extension,
 * initializes variables, opens the map, and starts the game. Otherwise, it
 * prints the correct usage of the program.
 */

int	main(int argc, char *argv[])
{
	t_data	data;

	printf(GREEN "\n*** Cub3D by Chaku & Oriol ***\n\n" NC);
	if (argc == 2)
	{
		data.map.filename = argv[1];
		if (check_extension(&data))
			print_error(&data, 3);
		init_variables(&data);
		open_map(&data);
		open_doors(&data);
		start_game(&data);
	}
	else
		printf("Usage: ./cub3d <map filename>\n");
}
