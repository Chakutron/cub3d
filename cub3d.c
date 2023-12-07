/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <mchiboub@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:30:45 by mchiboub          #+#    #+#             */
/*   Updated: 2023/12/07 13:39:19 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	main(int argc, char *argv[])
{
	t_data	data;

	init_variables(&data);
	printf("\n\n\033[0;32m*** Cub3D by Chaku & Oriol ***\033[0m\n\n");
	if (argc == 2)
	{
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			return (1);
		data.map.filename = argv[1];
		if (check_extension(&data))
			print_error(&data, 3);
		open_map(&data);
		mlx_do_key_autorepeaton(data.mlx_ptr);
		//unload_images(&data);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
	}
}