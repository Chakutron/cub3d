/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:12:11 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `check_extension` function verifies if the provided map file has the
 * correct extension ".cub". It checks if the last four characters of the
 * filename match ".cub", returning 0 if they do, indicating a valid extension,
 * and 1 otherwise.
 */

int	check_extension(t_data *data)
{
	int	i;

	i = ft_strlen(data->map.filename) - 4;
	if (i < 0)
		return (1);
	if (data->map.filename[i] == '.' && data->map.filename[i + 1] == 'c'
		&& data->map.filename[i + 2] == 'u' && data->map.filename[i + 3] == 'b')
		return (0);
	return (1);
}
