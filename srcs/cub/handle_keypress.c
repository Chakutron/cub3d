/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:52:45 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		data->endgame = 1;
	if (keysym == 119 || keysym == 65362)
		data->key.w = -1 + data->key.s;
	if (keysym == 115 || keysym == 65364)
		data->key.s = 1 + data->key.w;
	if (keysym == 97 || keysym == 65361)
		data->key.a = -1 + data->key.d;
	if (keysym == 100 || keysym == 65363)
		data->key.d = 1 + data->key.a;
	return (0);
}
