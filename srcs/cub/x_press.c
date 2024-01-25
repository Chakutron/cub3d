/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_press.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:49:43 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `x_press` function sets the `endgame` flag to 1, indicating that the user
 * has pressed the 'x' button on the window, typically used to close
 * the game or window.
 */

int	x_press(t_data *data)
{
	data->endgame = 1;
	return (0);
}
