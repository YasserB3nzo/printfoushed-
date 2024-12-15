/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datatype_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 23:27:45 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/13 19:10:32 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	datatype_check(char c, va_list args)
{
	int			count;
	const char	*bas;
	const char	*bas2;

	count = 0;
	bas = "0123456789abcedf";
	bas2 = "0123456789ABCEDF";
	if (c == 'd' || c == 'i')
		count = putnbrbase((long)va_arg(args, int), "0123456789", 10);
	else if (c == 'u')
		count = putnbrbase((long)va_arg(args, unsigned int), "0123456789", 10);
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'x')
		count = putnbrbase((unsigned int)va_arg(args, int), bas, 16);
	else if (c == 'X')
		count = putnbrbase((unsigned int)va_arg(args, int), bas2, 16);
	else if (c == 'p')
		count = putpointer(va_arg(args, unsigned long));
	else if (c == 'c')
		count = checkchar(c, args);
	return (count);
}
