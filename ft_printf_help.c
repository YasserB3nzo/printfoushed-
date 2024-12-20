/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:56:42 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/19 21:56:42 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkchar(int c)
{
	return (write(1, &c, 1));
}

int	checkputnbr(long *number)
{
	if (*number == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	if (*number < 0)
	{
		write(1, "-", 1);
		*number = - (*number);
		return (1);
	}
	return (2);
}

int	process_format(const char *str, va_list args)
{
	int	count;
	int	ret;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ret = datatype_check(*(++str), args);
			if (ret < 0)
			{
				return (-1);
			}
			count += ret;
		}
		else
		{
			write(1, str, 1);
			count++;
		}
		str++;
	}
	return (count);
}
