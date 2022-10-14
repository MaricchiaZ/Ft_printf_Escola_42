/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:27:59 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 23:12:08 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_len_hex(unsigned long n)
{
	int	i;

	i = 1;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_put_pt(unsigned long n)
{
	char				*hexa;
	unsigned long int	len;
	unsigned long int	div;
	char				*invert;
	int					i;

	div = n;
	if (!n)
		return (write(1, "(nil)", 5));
	i = check_len_hex(n);
	invert = ft_calloc (sizeof (char), (i + 1));
	hexa = "0123456789abcdef";
	len = write(1, "0x", 2);
	while (i > 0)
	{
		div = n % 16;
		invert[--i] = hexa[div];
		n = n / 16;
	}
	len += ft_putstr(invert);
	free (invert);
	return (len);
}
