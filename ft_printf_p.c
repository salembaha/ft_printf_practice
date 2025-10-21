/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabahass <sabahass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:57:31 by sabahass          #+#    #+#             */
/*   Updated: 2025/10/21 19:10:37 by sabahass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	ft_print_x_long(unsigned long n)
// {
// 	int		i;
// 	char	*hex_digits;

// 	i = 0;
// 	hex_digits = "0123456789abcdef";
// 	if (n >= 16)
// 	{
// 		i += ft_print_x_long(n / 16);
// 		if (i == -1)
// 			return (-1);
// 	}
// 	if (ft_print_c(hex_digits[n % 16]) == -1)
// 		return (-1);
// 	return (i + 1);
// }

int	ft_print_p(const void *p)
{
	int				i;
	int				hex_count;

	if (!p)
		return (ft_print_s("(nil)"));
	i = ft_print_s("0x");
	if (i == -1)
		return (-1);
	hex_count = ft_print_x((unsigned long)p, 0);
	if (hex_count == -1)
		return (-1);
	return (i + hex_count);
}
