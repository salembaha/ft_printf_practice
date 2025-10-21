/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabahass <sabahass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:16:01 by sabahass          #+#    #+#             */
/*   Updated: 2025/10/21 19:07:18 by sabahass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_dispatcher(char specifier, va_list *args)
{
	if (specifier == 'c')
		return (ft_print_c(va_arg(*args, int)));
	else if (specifier == 's')
		return (ft_print_s(va_arg(*args, const char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_d(va_arg(*args, int)));
	else if (specifier == 'u')
		return (ft_print_u(va_arg(*args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_x(va_arg(*args, unsigned int), (specifier == 'X')));
	else if (specifier == 'p')
		return (ft_print_p(va_arg(*args, const void *)));
	else if (specifier == '%')
		return (ft_print_c('%'));
	return (-1);
}

static int	process_format(const char *format, unsigned int *i, va_list *args)
{
	if (format[*i] == '%')
	{
		(*i)++;
		if (!format[*i])
			return (-1);
		char specifier = format[*i];
		(*i)++;
		return (format_dispatcher(specifier, args));
	}
	else
	{
		// int j = i;
		// while (format[j] && format[j] != '%')
		// 	++j;
		// if (write (1, &format[*i], j - *i) == -1)
		// 	return (-1);
		// *i = j;		

		char current_char = format[*i];
		(*i)++;
		if (write(1, &current_char, 1) != 1)
			return (-1);
		return (1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;
	int				total;
	int				result;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	total = 0;
	while (format[i])
	{
		result = process_format(format, &i, &args);
		if (result == -1)
			return (va_end(args), -1);
		total += result;
	}
	va_end(args);
	return (total);
}



// int	main(void)
// {
// 	int	x;

// 	x = 42;
// // test character printing
// 	ft_printf("test character printing\n");
// // cases
// 	ft_print_c('S');
// 	ft_print_c('\0');
// 	ft_print_c('\n');

// 	ft_printf("========\n");

// 	ft_printf("test character printing normal printf\n");
// 	printf("%c", 'S');
// 	printf("%c", '\0');
// 	ft_print_c('\n');


// // test string printing
// 	ft_printf("test string printing\n");
// // cases ft_
// 	ft_printf("str: %s\n", "hello");
// 	ft_printf("null: %s\n", NULL);
// 	ft_print_c('\n');

// 	ft_printf("========\n");

// 	ft_printf("test string printing normal printf\n");
// // cases printf
// 	printf("str: %s\n", "hello");
// 	printf("null: %s\n", (char *)NULL);
// 	ft_print_c('\n');

// // test signed decimal printing
// 	ft_printf("test decimal printing\n");
// // cases ft_
// 	ft_printf("Number: %d\n", 42);
// 	ft_printf("Negative: %d\n", -42);
// 	ft_printf("Zero: %i\n", 0);
// 	ft_print_c('\n');

// 	ft_printf("========\n");

// 	ft_printf("test decimal printing normal printf\n");
// // cases printf
// 	printf("Number: %d\n", 42);
// 	printf("Negative: %d\n", -42);
// 	printf("Zero: %i\n", 0);
// 	ft_print_c('\n');

// // test unsigned integer printing
// 	ft_printf("test integer printing\n");
// // cases ft_
// 	ft_printf("Unsigned: %u\n", 42u);
// 	ft_printf("Large: %u\n", 4294967295u);
// 	ft_printf("Zero: %u\n", 0u);
// 	ft_print_c('\n');

// 	ft_printf("========\n");

// 	printf("test integer printing normal printf\n");
// // cases printf
// 	printf("Unsigned: %u\n", 42u);
// 	printf("Large: %u\n", 4294967295u);
// 	printf("Zero: %u\n", 0u);
// 	ft_print_c('\n');

// // test hexadecimal printing
// 	ft_printf("test hexadecimal printing\n");
// // cases ft_
// 	ft_printf("Hex lower: %x\n", 255);
// 	ft_printf("Hex upper: %X\n", 255);
// 	ft_printf("Zero: %x\n", 0);
// 	ft_print_c('\n');

// 	ft_printf("========\n");

// 	printf("test hexadecimal printing normal printf\n");
// // cases printf
// 	printf("Hex lower: %x\n", 255);
// 	printf("Hex upper: %X\n", 255);
// 	printf("Zero: %x\n", 0);
// 	ft_print_c('\n');

// // test pointer printing
// 	ft_printf("test pointer printing\n");
// // cases ft_
// 	ft_printf("Address: %p\n", &x);
// 	ft_printf("NULL: %p\n", NULL);
// 	ft_print_c('\n');

// 	ft_printf("========\n");

// 	printf("test pointer printing normal printf\n");
// // cases printf
// 	printf("Address: %p\n", &x);
// 	printf("NULL: %p\n", NULL);
// 	ft_print_c('\n');

// // test percent sign
// 	ft_printf("test percent sign\n");
// // cases ft_
// 	ft_printf("Progress: 100%% complete\n");
// 	ft_printf("Literal %%\n");
// 	ft_print_c('\n');

// 	ft_printf("========\n");

// 	printf("test percent sign normal printf\n");
// // cases printf
// 	printf("Progress: 100%% complete\n");
// 	printf("Literal %%\n");
// 	ft_print_c('\n');

// 	return (0);
// }
