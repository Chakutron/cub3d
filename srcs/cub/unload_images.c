/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 20:03:56 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	unload_walk(t_data *data)
{
	int	i;

	i = 0;
	while (i <= 20)
	{
		mlx_destroy_image(data->mlx_ptr, data->player.walk.texture[i].ptr);
		i++;
	}
}

void	unload_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->map.NO_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.SO_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.EA_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.WE_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.D_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.F_image.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.C_image.ptr);
	unload_walk(data);
}
