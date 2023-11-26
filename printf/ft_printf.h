/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamoha <mohamoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:10:14 by mohamoha          #+#    #+#             */
/*   Updated: 2023/08/12 11:48:33 by mohamoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_print_num(int n);
int	ft_print_str(const char *str);
int	ft_print_hex(unsigned int n, char format);
int	ft_print_ptr(unsigned long n);
int	ft_print_unsigned(unsigned int n);
#endif