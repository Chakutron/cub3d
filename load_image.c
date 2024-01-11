/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/02 13:14:02 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	load_image(char *file, t_data *data)
{
	t_image image;
	image = new_file_img(file, data);
	printf("- Image loaded: (%s) (ptr=%p) (%ix%i pixels)\n", file, image.ptr, image.w, image.h);
	return (image);
}

void	unload_images(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->map.NO_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.SO_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.EA_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.WE_texture.ptr);
	/*mlx_destroy_image(data->mlx_ptr, data->map.NO_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.SO_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.WE_texture.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.EA_texture.ptr);*/
	mlx_destroy_image(data->mlx_ptr, data->map.F_image.ptr);
	mlx_destroy_image(data->mlx_ptr, data->map.C_image.ptr);
}