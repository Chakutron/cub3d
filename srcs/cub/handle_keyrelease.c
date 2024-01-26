/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyrelease.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/26 15:48:58 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `handle_keyrelease` function updates the key states and adjusts the
 * game's rendering ratio when keys are released. If the arrow keys or 'WASD'
 * keys are released, their corresponding movement flags are reset.
 * Additionally, pressing the '-' key decreases the rendering ratio, while
 * pressing the '+' key increases it, with limits set between 1 and 5.
 */

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == 119 || keysym == 65362)
		data->key.w = 0;
	if (keysym == 115 || keysym == 65364)
		data->key.s = 0;
	if (keysym == 97 || keysym == 65361)
		data->key.a = 0;
	if (keysym == 100 || keysym == 65363)
		data->key.d = 0;
	if (keysym == 65451 && data->bonus)
	{
		data->ratio -= 1;
		if (data->ratio < 1)
			data->ratio = 1;
		update(data);
	}
	if (keysym == 65453 && data->bonus)
	{
		data->ratio += 1;
		if (data->ratio > 5)
			data->ratio = 5;
		update(data);
	}
	return (0);
}
