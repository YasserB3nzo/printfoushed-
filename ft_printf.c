/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:24:08 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/17 23:48:51 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	putpointer(void	*ptr_address)
{
	int	count;

	count = 0;
	if (!ptr_address)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count += 2;
	count += putnbrbase((unsigned long)ptr_address, "0123456789abcdef", 16);
	return (count);
}

int	ft_printf(const char *datatype, ...)
{
	int		count;
	va_list	args;

	if (!datatype)
		return (-1);
	va_start(args, datatype);
	count = process_format(datatype, args);
	va_end(args);
	return (count);
}
