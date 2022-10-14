/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:21:19 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 23:20:53 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// essa função recebe um int positivo e imprime-o em hexadecimal
int ft_puthexa(unsigned int n) 
{
	char			*hexa; // criamos um pornteiro que receberá uma string 
	unsigned int	len; //variável que receberá a quantidade de caracteres impressos
	unsigned int	div; //receberá o tam no número em hexa e o resto da divisão (ou módulo)
	char			*invert; // string que receberá o número em hexa invertido
	int 			i; // índice que percorre a string

	div = n; // div rebece uma cópia de n
	i = 1; // i começa em 1 pois o menor tamanho do n em hexa é 1
	while (div >= 16) // enquanto o valor da de div for maior ou igual a 16, isso contará quantas casas
	// o número ocupa em hexadecimal
	{
		div = div / 16; // dividimos por 16
		i++; // acrescemos um 
	}
	invert = (char *) ft_calloc (sizeof (char), (i + 1)); //o ponteiro invert recebe o calloc (malloc + bzero)
	// de i + um byte para o '\0'
	hexa = "0123456789abcdef"; // a string hexa recebe a base hexadecimal
	len = 0; // a quantidade de caracteres impressos começa zerada
	div = 0; // e zeramos a variável div, agora ela passará a receber o módulo do n por 16
	i--; // voltamos 1 casa, pois a última é o byte nulo
	while  (i >= 0) // enquanto não acabarmos de preencher a string (estamos preenchendo do fim para o começo)
	{
		div = n % 16; // div recebe o resto de n por 16
		invert[i] = hexa[div]; // armazenamos o resto já na base 16 na string invert
		n = n / 16;  // dividimos o n pela base
		i--; // retornamos uma casa na nossa string
	}
	len = ft_putstr(invert); // a impressão da string será feita pela função ft_putstr que retornará a 
	// quantidade de caracteres impressos
	free (invert); // liberamos o ponteiro que recebeu a alocação
	return (len); // retornamos a quantidade de caracteres impressos
}


int ft_puthexa_upper(unsigned int n)
{
	char			*hexa; // criamos um pornteiro que receberá uma string 
	unsigned int	len; //variável que receberá a quantidade de caracteres impressos
	unsigned int	div; //receberá o tam no número em hexa e o resto da divisão (ou módulo)
	char			*invert; // string que receberá o número em hexa invertido
	int 			i; // índice que percorre a string

	div = n; // div rebece uma cópia de n
	i = 1; // i começa em 1 pois o menor tamanho do n em hexa é 1
	while (div >= 16)  // enquanto o valor da de div for maior ou igual a 16, isso contará quantas casas
	// o número ocupa em hexadecimal
	{
		div = div / 16; // dividimos por 16
		i++; // acrescemos um
	}
	invert = (char *) ft_calloc (sizeof (char), (i + 1)); //o ponteiro invert recebe o calloc (malloc + bzero)
	// de i + um byte para o '\0'
	hexa = "0123456789ABCDEF";  // a string hexa recebe a base hexadecimal maiúscula
	len = 0; // a quantidade de caracteres impressos começa zerada
	div = 0; // e zeramos a variável div, agora ela passará a receber o módulo do n por 16
	i--; // voltamos 1 casa, pois a última é o byte nulo
	while (i >= 0) // enquanto não acabarmos de preencher a string (estamos preenchendo do fim para o começo)
	{
		div = n % 16; // div recebe o resto de n por 16
		invert[i] = hexa[div];  // armazenamos o resto já na base 16 na string invert
		n = n / 16; // dividimos o n pela base
		i--; // retornamos uma casa na nossa string
	}
	len = ft_putstr(invert); // a impressão da string será feita pela função ft_putstr que retornará a 
	// quantidade de caracteres impressos
	free (invert); // damos um free no ponteiro que recebeu a alocação
	return (len); // retornamos a quantidade de caracteres impressos
}
