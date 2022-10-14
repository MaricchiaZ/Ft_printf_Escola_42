/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:00:04 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 22:31:50 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	i = 2; 
	int	j = 214748364;
	int	k = 12456;

	char a = 'a';
	char b = 'b';
	char c = 'c';

	char tab[5] = {"amor"};
	char string[6] = {"amora"};
	ft_printf("sem variáveis\n");
	ft_printf("%i\n", i);
	ft_printf("%i\n", j);
	ft_printf("%i\n", k);

	ft_printf("%c\n", a);
	ft_printf("%c\n", b);
	ft_printf("%c\n", c);

	ft_printf("%s\n", tab);
	ft_printf("%s\n", string);

	ft_printf("%%\n");
	ft_printf("%% \n");

}