/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/16 18:15:21 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `draw_background` function draws the background of the game by placing
 * the ceiling and floor images onto the canvas. It copies the ceiling image to
 * the top half of the canvas and the floor image to the bottom half.
 */

void	draw_background(t_data *data)
{
	put_img_to_img(&data->canvas, &(data->map.C_image), 0, 0);
	put_img_to_img(&data->canvas, &(data->map.F_image), 0, HEIGHT / 2);
}
