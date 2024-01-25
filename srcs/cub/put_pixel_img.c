/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:41:11 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:55:49 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `put_pixel_img` function sets the color of a pixel at coordinates
 * `(x, y)` in the given image `img`. It calculates the memory address of the
 * pixel using the image's address, line length, bits per pixel, and the
 * coordinates `(x, y)`, and then sets the color of the pixel at that address.
 * If the color is transparent (0xFF000000), it skips setting the pixel.
 */

void	put_pixel_img(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr;
	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img->w && y < img->h)
	{
		dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *) dst = color;
	}
}
