/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 20:04:16 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `load_image` function loads an image from a file and returns a `t_image`
 * structure containing information about the loaded image. It prints a message
 * indicating the successful loading of the image along with its file name,
 * pointer address, and dimensions.
 */

t_image	load_image(char *file, t_data *data)
{
	t_image	image;

	image = new_file_img(file, data);
	printf("- Image loaded: (%s) (ptr=%p) (%ix%i pixels)\n",
		file, image.ptr, image.w, image.h);
	return (image);
}
