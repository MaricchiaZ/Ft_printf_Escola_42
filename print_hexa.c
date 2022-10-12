/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:21:19 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/12 05:44:34 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_puthexa(unsigned int    n)
{
    char    *hexa;
    int        len;
    int        sten;
    int        div;

    hexa = "0123456789abcdef";
    sten = 1;
    len = 0;    
    while (sten <= n / 16)
        sten = sten * 16;
    if (n > 16)
    {
        div = n / sten;
        len += write(1, &hexa[div], 1);
        sten = sten / 16;
        n = n / 16;    
    }
    while (n > 16)
    {
        len += write(1, &hexa[n % sten], 1);
        sten = sten / 16;
        n = n / 16;    
    }
  if (n <= 16)
    len += write(1, &hexa[n], 1);
    return (len);
}

int ft_puthexa_upper(unsigned int n)
{
	char	*hexa;
	int		len;

	hexa = "0123456789ABCDEF";
	len = 0;
	len += write(1, &hexa[n / 16], 1);
	len += write(1, &hexa[n % 16], 1);
	return (len);
}
