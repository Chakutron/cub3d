/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <mchiboub@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:24:53 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:44:57 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* 
 * The `create_trgb` function creates a single integer representing a color in
 * the format of 0xTTRRGGBB, where T is the transparency value, R is the red
 * value, G is the green value, and B is the blue value. It combines the input
 * values for transparency, red, green, and blue into a single integer
 * representing the color.
 */

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
