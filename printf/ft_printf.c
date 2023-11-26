/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:09:33 by mohamoha          #+#    #+#             */
/*   Updated: 2023/08/17 14:58:15 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		print_length += ft_print_num(va_arg(args, int));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(args, unsigned long));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_putchar('%');
	return (print_length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start (args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			len += ft_print_formats(args, format[++i]);
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end (args);
	return (len);
}
#include <stdio.h>
int main(void)
{
	ft_printf("%u\n", -1123);
	printf("%u\n", -1123);
}
