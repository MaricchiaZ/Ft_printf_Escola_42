/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:59:52 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/01 12:59:52 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*str;
	const char	*to_find;
	size_t		i;
	size_t		p;

	i = 0;
	str = s1;
	to_find = s2;
	if (to_find[i] == '\0')
		return ((char *)str);
	p = 0;
	while (str[i] != '\0' && p < n)
	{
		p = 0;
		while (str[i + p] == to_find[p] && str[i + p] != '\0' && i + p < n)
		{
			if (to_find[p + 1] == '\0')
				return (&((char *)str)[i]);
			p++;
		}
		i++;
	}
	return (NULL);
}
