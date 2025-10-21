/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabahass <sabahass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:01:51 by sabahass          #+#    #+#             */
/*   Updated: 2025/10/21 19:10:08 by sabahass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x_long(unsigned long n, const char *hex_digits)
{
	int		count;

	count = 0;
	if (n >= 16)
	{
		count += ft_print_x_long(n / 16, hex_digits);
		if (count == -1)
			return (-1);
	}
	if (ft_print_c(hex_digits[n % 16]) == -1)
		return (-1);
	return (count + 1);
}

int	ft_print_x(unsigned long n, int upper)
{
	if (upper)
		return (ft_print_x_long((unsigned long)n, "0123456789ABCDEF"));
	return (ft_print_x_long((unsigned long)n, "0123456789abcdef"));
}
