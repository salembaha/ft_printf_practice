/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabahass <sabahass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:05:00 by sabahass          #+#    #+#             */
/*   Updated: 2025/10/21 18:59:13 by sabahass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d(int n)
{
	char	*str;
	int		i;
	// ssize_t	w;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	i = ft_strlen(str);
	if (write(1, str, i) == -1)
		return (free(str), -1);
	return (free(str), i);

	// while (str[i])
	// {
	// 	w = write(1, &str[i], 1);
	// 	if (w != 1)
	// 		return (free(str), -1);
	// 	i++;
	// }
	// free(str);
	// return (i);
}

// putnbr linken/ gebruik logic van putnumber 
