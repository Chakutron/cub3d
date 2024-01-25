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

char	*ft_itoa(int n)
{
	long int	num;
	int			size;
	char		*str;

	num = n;
	size = check_size(num);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	worker(str, size, num);
	return (str);
}
