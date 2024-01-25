/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:13:35 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `finish_gnl` function reads and discards all remaining lines from the
 * file descriptor until reaching the end of the file. Finally, it closes
 * the file descriptor.
 */

void	finish_gnl(t_data *data)
{
	while (data->line != NULL)
	{
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	close(data->fd);
}
