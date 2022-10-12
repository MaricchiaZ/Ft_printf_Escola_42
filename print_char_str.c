/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:05:51 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/12 01:09:23 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str) // essa função imprime uma string na tela
{
	int	i; // criamos um inteiro i, para ser o índice que percorrerá a string
	int	len; // COMENTARRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR

	i = 0; // atribuímos a ele o valor zero
	len = 0;
	while (str[i] != '\0') //enquanto a string recebida na posição i for diferente do
	// byte nulo
	{
		len += write(1, &str[i], 1); // mandamos o caracter da posição i, para a função write e assim imprimimos na tela
		i++; // acrescentando um no valor de i, avançamos para a próxima posição da string 
	}
	return (len);
}

