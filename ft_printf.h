/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabahass <sabahass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:26:43 by sabahass          #+#    #+#             */
/*   Updated: 2025/10/21 19:10:24 by sabahass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_c(int c);
int	ft_print_s(const char *s);
int	ft_print_d(int n);
int	ft_print_u(unsigned int n);
int	ft_print_x(unsigned long n, int upper);
int	ft_print_p(const void *p);

#endif
