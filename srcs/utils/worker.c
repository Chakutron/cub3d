/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:55:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/04/18 12:33:42 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	worker(char *str, int size, long int num)
{
	int	neg;

	neg = 0;
	str[size] = '\0';
	if (num < 0)
	{
		num *= -1;
		neg = 1;
		size--;
	}
	while (size)
	{
		str[size + neg - 1] = 48 + (num % 10);
		num /= 10;
		size--;
	}
	if (neg)
		str[0] = '-';
}
