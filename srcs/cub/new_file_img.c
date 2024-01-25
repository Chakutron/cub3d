/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:41:11 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:55:07 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `new_file_img` function loads an image file located at the specified
 * `path` using the mlx library, retrieves its width and height, and returns a
 * `t_image` structure containing information about the loaded image.
 * If the image loading fails, an error message is printed.
 */

t_image	new_file_img(char *path, t_data *window)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(window->mlx_ptr, path, &img.w, &img.h);
	if (!img.ptr)
	{
		printf("Error loading image file..\n");
	}
	img.addr = mlx_get_data_addr(img.ptr, &(img.bpp),
			&(img.line_len), &(img.endian));
	return (img);
}
