/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:51:21 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `handle_mouse_move` function tracks mouse movement within the window.
 * When the mouse moves left (`x < WIDTH / 2`), it sets the 'A' key state and
 * adjusts the cursor's horizontal position accordingly. Conversely, when the
 * mouse moves right (`x > WIDTH / 2`), it sets the 'D' key state and adjusts
 * the cursor's horizontal position. If neither condition is met, it resets the
 * cursor's horizontal position to 0.
 */

int	handle_mouse_move(int x, int y, t_data *data)
{
	(void)y;
	if (x < WIDTH / 2)
	{
		data->key.a = 1 + data->key.d;
		data->cursor_x = abs(WIDTH / 2 - x) / 10;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, WIDTH / 2, HEIGHT / 2);
	}
	else
		data->key.a = 0;
	if (x > WIDTH / 2)
	{
		data->key.d = 1 + data->key.a;
		data->cursor_x = abs(WIDTH / 2 - x) / 10;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, WIDTH / 2, HEIGHT / 2);
	}
	else
		data->key.d = 0;
	if (data->key.a == 0 && data->key.d == 0)
		data->cursor_x = 0;
	return (0);
}
