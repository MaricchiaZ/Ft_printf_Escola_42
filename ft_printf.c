/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:55:48 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/12 01:36:18 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_format(const char *fmt, int i, va_list args)
{
	if (fmt[i] == 'c') //cspdiuxX%
		ft_putchar(va_arg(args, int)); // imprime um char
	if (fmt[i] == 's')
		ft_putstr(va_arg(args, char *)); //imprime uma string
//	if (fmt[i] == 'p')
//		ft_putp(va_arg(args, unsigned long)); //imprime em hexa
	if (fmt[i] == 'd')
		ft_putnbr(va_arg(args, int)); //imprime número com sinal, maiores ou menores que zero
	if (fmt[i] == 'i')
		ft_putnbr(va_arg(args, int)); //imprime qualquer int
	if (fmt[i] == 'u')
		ft_put_u_nbr(va_arg(args, unsigned int)); //imprime número sem sinal, apenas maiores que zero
	if (fmt[i] == 'x')
		ft_puthexa(va_arg(args, unsigned int)); //imprime em hexa minúsculo
	if (fmt[i] == 'X')
		ft_puthexa_upper(va_arg(args, unsigned int)); //imprime em hexa maiúsculo
	if (fmt[i] == '%')
		ft_putchar('%'); // imprime apenas um %
	return(0);
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

/*
t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0; // configuramos tudo para 0, falso
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->tl = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->perc = 0;
	tab->sp = 0;
	return (tab);
}


int	ft_eval_format(t_print tab, char *format, int i)
{
	while(format[i] != 'c' || format[i] != 's' || format[i] != 'p' \
	|| format[i] != 'd' || format[i] != 'i' || format[i] != 'u'  \
	|| format[i] != 'x'|| format[i] != 'X' || format[i] != '%' )  // enquanto não cspdiuxX%
	{
		if (format[i] == '.')
			tab->pnt = 1; //configuramos como true, 1 
		if (formato[i] == '-')
			tab->dash = 1; //configuramos como true, 1
		if (formato[i] == '-' || formato[i] == '+' )
			tab->sign = 1; //configuramos como true, 1
		if (formato[i] == '0')
			tab->is_zero = 1; //configuramos como true, 1 
		if (formato[i] == '%')
			tab->perc = 1; //configuramos como true, 1
		if (formato[i] == ' ')
			tab->sp = 1; //configuramos como true, 1 
		i++; 	
	}
	if (format[i] == 'c') 
   		ft_print_char(tab); 
	if (format[i] == 'd' || format[i] == 'i') 
   		ft_print_integer(tab); 
//etc
}

int	vsprintf(const char *format, ...)
{
	int	i;
	int	nbr_ret;
	t_print *tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = 0;
	len_ret = 0;
	while(format[i]) // enquanto a string existir
	{
		if (format[i] == '%') // se o caracter for %
			i = ft_eval_format(tab, format, i + 1); // função que avalia o formato passado
		else
			len_ret = len_ret + write(1, &format[i], 1); // imprime o caracter que tem
			// em format[i] e em seguida soma o retorno o write no 'length return' 
			// a função write tem um retorno inteiro que é a quantidade de caracteres impressos
		i++;
	}
	va_end(tab->args);
	len_ret = len_ret + tab->tl;
	free (tab);
	return (len_ret);
}
*/