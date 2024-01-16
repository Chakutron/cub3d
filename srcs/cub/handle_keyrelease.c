/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:53:20 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (keysym == 65451)
	{
		data->ratio -= 1;
		if (data->ratio < 1)
			data->ratio = 1;
		update(data);
	}
	if (keysym == 65453)
	{
		data->ratio += 1;
		if (data->ratio > 5)
			data->ratio = 5;
		update(data);
	}
	return (0);
}
