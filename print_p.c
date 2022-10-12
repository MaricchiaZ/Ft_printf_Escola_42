/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:27:59 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/12 01:34:16 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int ft_puthexa_p(unsigned long i)
{
	char	*hexa;
	int 	i;
	int		j;
	int		len;

	hexa = "0123456789abcdef";
	i = 0;
	len = 0;
	len += write(1, "0x", 2);
	while (str[i] != '\0')
	{
		j = str[i];
		len += write(1, &hexa[j / 16], 1);
		len += write(1, &hexa[j % 16], 1);
		i++;
	}
	return (len);
}

int	ft_putp(unsigned long i)
{
	
}
