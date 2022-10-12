/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:23:44 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/14 17:38:20 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;
	size_t	len_dest;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (size < len_dest + 1)
		return (len_src + size);
	i = 0;
	if (size >= len_dest + 1)
	{
		while (src[i] && len_dest + i < size - 1)
		{
			dest[len_dest + i] = src[i];
			i++;
		}		
	}
	dest[len_dest + i] = '\0';
	return (len_src + len_dest);
}
