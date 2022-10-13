/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:00:04 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 11:06:42 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	// int	i = 2;
	// int	j = 214748364;
	// int	k = 12456;

	// char a = 'a';
	// char b = 'b';
	// char c = 'c';

	// char tab[5] = {"amor"};
	// char string[6] = {"amora"};
	// ft_printf("sem variáveis\n");
	// ft_printf("oi %i oi\n", i);
	// ft_printf("oi %i oi\n", j);
	// ft_printf("%i\n", k);

	// ft_printf("oi %c oi\n", a);
	// ft_printf("%c\n", b);
	// ft_printf("%c\n", c);

	// ft_printf("oi %s oi\n", tab);
	// ft_printf("%s\n", string);

	// ft_printf("%%\n");
	// ft_printf("oi %% oi\n");

	// ft_printf("hexa\n");
	// ft_printf("oi %x oi\n", i);
	// printf("o %x o\n", i);
	// ft_printf("\n");
	// ft_printf("oi %x oi\n", j);
	// printf("o %x o\n", j);
	// ft_printf("\n");
	// ft_printf("oi %x oi\n", k);
	// printf("o %x o\n", k);

	// int	l = 7262;
	// ft_printf("\n");
	// ft_printf("oi %x oi\n", l);
	// printf("o %x o\n", l);

	// int	m = 35631;
	// ft_printf("\n");
	// ft_printf("oi %x oi\n", m);
	// printf("o %x o\n", m);

	ft_printf("\n");
	ft_printf("This %p is even stranger\n", (void *)-1);
	ft_printf("\n");
	printf("This %p is even stranger\n", (void *)-1);

}