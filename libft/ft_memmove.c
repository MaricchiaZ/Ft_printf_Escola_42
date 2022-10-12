/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:47:51 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/09 02:33:39 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*temp;
	size_t				i;

	i = 0;
	d = (unsigned char *) dest;
	temp = (const unsigned char *) src;
	if ((!d && !temp) || !n)
		return (dest);
	if (d <= temp)
	{
		while (i < n)
		{
			d[i] = temp[i];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
