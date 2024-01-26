/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/26 16:01:19 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `unload_walk` function deallocates the memory used by the textures of
 * the walking animation in the game.
 */

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

/*
 * The `unload_images` function deallocates the memory used by the loaded 
 * images in the game.
 */

void	unload_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->map.no_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.so_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.ea_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.we_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.d_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.f_image.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.c_image.ptr);
	unload_walk(data);
}
