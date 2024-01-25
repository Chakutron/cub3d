/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:41:11 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:56:19 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `get_pixel_img` function retrieves the color of a pixel at coordinates
 * (x, y) from the given image `img`. It calculates the memory address of the
 * pixel using the image's address, line length, and bits per pixel (bpp), then
 * dereferences the address to obtain the color value as an unsigned integer.
 */

unsigned int	get_pixel_img(t_image *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (abs(y) * img->line_len)
			+ (abs(x) * img->bpp / 8))));
}
