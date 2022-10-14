/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:27:59 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 23:24:10 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// função auxiliar que contará quantas casas o número ocupa em hexadecimal
static int	check_len_hex(unsigned long n)
{
	int	i; // variável auxiliar contar quantas casas o número ocupa em hexadecimal

	i = 1; // i começa em 1 pois o menor tamanho do n em hexa é 1
	while (n >= 16)  // enquanto o valor da de div for maior ou igual a 16, isso contará quantas casas
	{
		n = n / 16;  // dividimos o n por 16
		i++;  // acrescemos um
	}
	return (i); //retornamos o número de casas que o número ocupa em hexa
}

//função que recebe um unsigned long refente a memória de um ponteiro e fará a conversão para hexadecimal
//e imprimirá caracter a caracter, uma memória comeca com 0x e em seguida tem o hexa do unsigned long
int	ft_put_pt(unsigned long n)
{
	char				*hexa; // criamos um pornteiro que receberá uma string 
	unsigned long int	len; //variável que receberá a quantidade de caracteres impressos
	unsigned long int	div;  //receberá o tam no número em hexa e o resto da divisão (ou módulo
	char				*invert;  // string que receberá o número em hexa invertido
	int					i;  // índice que percorre a string

	div = n; // div rebece uma cópia de n
	if (!n) // se o ponteiro estiver vazio
		return (write(1, "(nil)", 5)); // escrevemos (nil) com a função write, e como essa função além de 
		// escrever, retorna a quantidade de bytes escritos, podemos usá-la no return()
	i = check_len_hex(n); //i recebe o retorno da funçao que obtém o número de casas que o número ocupa em hexa
	invert = ft_calloc (sizeof (char), (i + 1)); //o ponteiro invert recebe o calloc (malloc + bzero)
	// de i + um byte para o '\0'
	hexa = "0123456789abcdef"; // a string hexa recebe a base hexadecimal
	len = write(1, "0x", 2); // já imprimimos o inicio de um endereço de memória e guardamos em len essa quantidade de 2 caracteres que retorna da função write
	while (i > 0) // enquanto não acabarmos de preencher a string (estamos preenchendo do fim para o começo)
	{
		div = n % 16; // div recebe o resto de n por 16
		invert[--i] = hexa[div];// voltamos 1 casa, pois a última é o byte nulo
		// armazenamos o resto já na base 16 na string invert
		// retornamos uma casa na nossa string antes da próxima adição
		n = n / 16;  // dividimos o n pela base
	}
	len += ft_putstr(invert);// a impressão da string será feita pela função ft_putstr que retornará a 
	// quantidade de caracteres impressos que é somada em len
	free (invert);  // liberamos o ponteiro que recebeu a alocação
	return (len);  // retornamos a quantidade de caracteres impressos
}
