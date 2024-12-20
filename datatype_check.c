/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatype_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:56:33 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/19 21:58:51 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	datatype_check(char c, va_list args)
{
	int			count;

	count = 0;
	if (c == 'd' || c == 'i')
		count = putnbrbase((long)va_arg(args, int), "0123456789", 10);
	else if (c == 'u')
		count = putnbrbase((long)va_arg(args, unsigned int), "0123456789", 10);
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'x')
		count = putnbrbase((unsigned int)va_arg(args, int), BASE_DECI, 16);
	else if (c == 'X')
		count = putnbrbase((unsigned int)va_arg(args, int), BASE_HEXA, 16);
	else if (c == 'p')
		count = putpointer(va_arg(args, void *));
	else if (c == 'c')
		count = checkchar(va_arg(args, int));
	else if (c == '%')
		count = checkchar(c);
	return (count);
}
