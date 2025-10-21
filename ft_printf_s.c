/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabahass <sabahass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:16:50 by sabahass          #+#    #+#             */
/*   Updated: 2025/10/21 18:58:46 by sabahass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(const char *s)
{
	int		i;
	ssize_t	w;

	if (!s)
		s = "(null)";
	i = 0;
	// ft_strlen(s); // use strlen + write (same as ft_print_d)
	
	while (s[i])
	{
		w = write(1, &s[i], 1);
		if (w != 1)
			return (-1);
		i++;
	}
	return (i);
}
