/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:49:39 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/14 17:19:34 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert_char_int(int n, int fd)
{
	char	c;

	c = '0';
	c = c + n;
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	ten;

	ten = 1;
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	while (ten <= n / 10)
		ten = ten * 10;
	while (ten >= 1)
	{
		convert_char_int ((n / ten), fd);
		n = n - (n / ten) * ten;
		ten = ten / 10;
	}		
}
