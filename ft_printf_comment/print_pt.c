/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:27:59 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 12:02:50 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_pt(unsigned long n)
{
	char				*hexa;
	unsigned long int	len;
	unsigned long int	div;
	char				*invert;
	int 				i;

	div = n;
	i = 1;
	if (!n)
		return (write(1, "(nil)", 5));
	while (div >= 16)
	{
		div = div / 16;
		i++;
	}
	invert = ft_calloc (sizeof (char), (i + 1));
	hexa = "0123456789abcdef";
	len = 0;
	div = 0;
	len += write(1, "0x", 2);
	i--;
	while ( i>=0 )
	{
		div = n % 16;
		invert[i] = hexa[div];
		n = n / 16;
		i--;
	}
	len += ft_putstr(invert);
	free (invert);
	return (len);
}
