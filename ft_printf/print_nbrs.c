/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:55:44 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 14:06:32 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_char_int(int n)
{
	char	c;

	c = '0';
	c = c + n;
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int			ten;
	long int	nb;
	int			len;

	nb = n;
	ten = 1;
	len = 0;
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = nb * -1;
	}
	while (ten <= nb / 10)
		ten = ten * 10;
	while (ten >= 1)
	{
		len += convert_char_int (nb / ten);
		nb = nb - (nb / ten) * ten;
		ten = ten / 10;
	}
	return (len);
}

int	ft_put_u_nbr(unsigned int n)
{
	unsigned int	ten;
	unsigned int	len;

	len = 0;
	ten = 1;
	while (ten <= n / 10)
		ten = ten * 10;
	while (ten >= 1)
	{
		len += convert_char_int (n / ten);
		n = n - (n / ten) * ten;
		ten = ten / 10;
	}
	return (len);
}
