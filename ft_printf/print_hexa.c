/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:21:19 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 12:54:27 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int n)
{
	char			*hexa;
	unsigned int	len;
	unsigned int	div;
	char			*invert;
	int				i;

	div = n;
	i = 1;
	while (div >= 16)
	{
		div = div / 16;
		i++;
	}
	invert = (char *) ft_calloc (sizeof (char), (i + 1));
	hexa = "0123456789abcdef";
	while (i > 0)
	{
		div = n % 16;
		invert[--i] = hexa[div];
		n = n / 16;
	}
	len = ft_putstr(invert);
	free (invert);
	return (len);
}

int	ft_puthexa_upper(unsigned int n)
{
	char			*hexa;
	unsigned int	len;
	unsigned int	div;
	char			*invert;
	int				i;

	div = n;
	i = 1;
	while (div >= 16)
	{
		div = div / 16;
		i++;
	}
	invert = (char *) ft_calloc (sizeof (char), (i + 1));
	hexa = "0123456789ABCDEF";
	while (i > 0)
	{
		div = n % 16;
		invert[--i] = hexa[div];
		n = n / 16;
	}
	len = ft_putstr(invert);
	free (invert);
	return (len);
}
