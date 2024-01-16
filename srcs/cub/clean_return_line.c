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
