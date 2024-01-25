/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_return_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:17:30 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `clean_return_line` function removes trailing newline characters from a
 * string. It checks if the last character is a newline (`\n`) and removes it.
 * Additionally, it checks if the character before the newline is a carriage
 * return (`\r`) and removes it as well, if present. This ensures consistent
 * line ending handling.
 */

void	clean_return_line(char *str)
{
	if (str[ft_strlen(str) - 1] == '\n')
	{
		if (str[ft_strlen(str) - 2] == '\r')
			str[ft_strlen(str) - 2] = '\0';
		else
			str[ft_strlen(str) - 1] = '\0';
	}
}
