/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbrbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:24:20 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/15 15:39:32 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbrbase(long number, const char *base, int base_length)
{
	int		count;
	int		i;
	char	result[75];
	int		check;

	count = 0;
	i = 0;
	check = checkputnbr(&number);
	if (check == 0)
		return (1);
	if (check == 1)
		count++;
	while (number)
	{
		result[i++] = base[number % base_length];
		number /= base_length;
	}
	while (--i >= 0)
	{
		write(1, &result[i], 1);
		count++;
	}
	return (count + 1);
}
