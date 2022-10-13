/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:55:48 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 11:36:02 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(const char *fmt, int i, va_list args)
{
	int len;

	len = 0;
	if (fmt[i] == 'c') //cspdiuxX%
		len = ft_putchar(va_arg(args, int)); // imprime um char
	if (fmt[i] == 's')
		len = ft_putstr(va_arg(args, char *)); //imprime uma string
	if (fmt[i] == 'p')
		len = ft_put_pt(va_arg(args, unsigned long)); //imprime em hexa
	if (fmt[i] == 'd')
		len = ft_putnbr(va_arg(args, int)); //imprime número com sinal, maiores ou menores que zero
	if (fmt[i] == 'i')
		len = ft_putnbr(va_arg(args, int)); //imprime qualquer int
	if (fmt[i] == 'u')
		len = ft_put_u_nbr(va_arg(args, unsigned int)); //imprime número sem sinal, apenas maiores que zero
	if (fmt[i] == 'x')
		len = ft_puthexa(va_arg(args, unsigned int)); //imprime em hexa minúsculo
	if (fmt[i] == 'X')
		len = ft_puthexa_upper(va_arg(args, unsigned int)); //imprime em hexa maiúsculo
	if (fmt[i] == '%')
		len = ft_putchar('%'); // imprime apenas um %
	return(len);
}

static int	make_print_buffer(const char *fmt, va_list args)
{
	int	i;
	int	len_str;

	i = 0;
	len_str = 0;
	while(fmt[i]) // enquanto a string existir
	{
		if (fmt[i] == '%') // se o caracter for %
		{
			len_str += print_format(fmt, i + 1, args); // função que avalia o formato passado
			i++;
		}
		else
		{
			len_str += write(1, &fmt[i], 1); // armazena a string fmt em print_buffer enquanto não for %_
		}
		i++;
	}
	return (len_str);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		printed;

	va_start(args, fmt);
	printed = make_print_buffer(fmt, args);
	va_end(args);
	return (printed);
}
