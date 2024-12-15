/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 23:06:43 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/15 15:34:31 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putstr(const char *str);
int	putnbrbase(long number, const char *base, int base_length);
int	putpointer(void *ptr_address);
int	datatype_check(char c, va_list args);
int	ft_printf(const char *datatype, ...);
int	checkchar(int c);
int	checkputnbr(long *number);
int	process_format(const char *str, va_list args);

#endif
