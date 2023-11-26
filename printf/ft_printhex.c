/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:21:58 by mohamoha          #+#    #+#             */
/*   Updated: 2023/08/12 11:49:41 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char format)
{
	char	*hex;
	int		counter;

	counter = 0;
	hex = "0123456789abcdef";
	if (format == 'X')
		hex = "0123456789ABCDEF";
	if (n > 15)
	{
		counter += ft_print_hex(n / 16, format);
		counter += ft_print_hex(n % 16, format);
	}
	else
	{
		ft_putchar(hex[n]);
		counter++;
	}
	return (counter);
}
