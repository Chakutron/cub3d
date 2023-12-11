/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocassany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:25:17 by ocassany          #+#    #+#             */
/*   Updated: 2023/11/05 15:28:19 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (str[i] == '-')
		return (-42);
	while (str[i])
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (res > 255)
		return (-42);
	return (res);
}
