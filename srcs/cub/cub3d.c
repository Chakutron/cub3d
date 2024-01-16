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
		start_game(&data);
	}
	else
		printf("Usage: ./cub3d <map filename>\n");
}
