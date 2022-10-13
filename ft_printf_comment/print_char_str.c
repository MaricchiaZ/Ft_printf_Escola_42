/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:05:51 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 12:01:20 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c) // essa função imprime um caracter na tela
{
	write(1, &c, 1); // imprime o caracter armazenado na variável c
	return (1); // retorna 1, pois apenas um caracter foi impresso
}

int	ft_putstr(char *str) // essa função imprime uma string na tela
{
	int	i; // criamos um inteiro i, para ser o índice que percorrerá a string
	int	len; // criamos uma variável para armazenar a quantidade de caracteres impressos

	i = 0; // atribuímos a ele o valor zero
	len = 0; // enquanto não imprimirmos nada, ele vale 0
	if (!str)
		return(write(1,"(null)", 6));
	while (str[i] != '\0') //enquanto a string recebida na posição i for diferente do
	// byte nulo
	{
		len += write(1, &str[i], 1); // mandamos o caracter da posição i, para a função write e assim imprimimos na t},
		// e a variável que armazena a quantidade de caracteres impressos vai ganhando valor
i++; // acrescentando um no valor de i, avançamos para a próxima posição da string
	}
	return (len); // retornamos a quantidade de caracteres impressos
}
