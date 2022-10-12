/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 21:04:23 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/05 17:31:32 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*src;

	i = 0;
	src = (unsigned char *)s;
	while (n)
	{
		if (src[i] == (unsigned char) c)
			return (&((void *)src)[i]);
		i++;
		n--;
	}
	return (NULL);
}
