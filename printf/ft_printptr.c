/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:21:44 by mohamoha          #+#    #+#             */
/*   Updated: 2023/08/12 11:52:36 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_ptr(unsigned long n)
{
	char	*hex;
	int		counter;

	counter = 0;
	hex = "0123456789abcdef";
	if (n > 15)
	{
		counter += ft_get_ptr(n / 16);
		counter += ft_get_ptr(n % 16);
	}
	else
	{
		ft_putchar(hex[n]);
		counter++;
	}
	return (counter);
}

int	ft_print_ptr(unsigned long n)
{
	int	count;

	count = 0;
	count += ft_print_str("0x");
	count += ft_get_ptr(n);
	return (count);
}
