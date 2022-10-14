/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:55:44 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 22:46:27 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// esta função auxiliar converte o valor do int para o valor dele em ASCII e "imprime"
static int	convert_char_int(int n)
{
	char	c; // criamos um char auxiliar

	c = '0'; // esse char recebe o valor do zero na tabela ASCII
	c = c + n; // o zero é adicionado ao int n passado, assim passamos a ter um char com o mesmo valor desse n
	write (1, &c, 1); //no descritor passado,  colocamos o conteúdo de c
	return (1); // retornamos 1, pois é a quantidade de caracter impresso a cada chamada
}

//função que recebe um int a partir do qual fará a "impressão" caracter a caracter
int	ft_putnbr(int n)
{
	int			ten; // int auxiliar que receberá a potência de 10 referente ao número;
	long int	nb; // criamos um long int para receber o n
	int			len; // varíavel que receberá a quantidade de caracteres impressos

	nb = n;
	ten = 1; // potência de 10 inicia-se em 1
	len = 0; // a quantidade de caracteres impressos inicia-se em zero
	if (nb < 0) // se o número fot menor do que zero
	{
		len +=write(1, "-", 1); // já imprimimos o '-'
		nb = nb * -1; // nosso número é multiplicado por -1 e passa a ser positivo agora
	}
	while (ten <= nb / 10) // enquanto a potência de 10 tiver menos casas do que o número passado
		ten = ten * 10;  // multiplicamos essa potência por dez
	while (ten >= 1) // enquanto a potência de 10 for maior ou igual a 1
	{
		len += convert_char_int (nb / ten); //número dividido pela potência de 10 (essa divisão fornece como
	// resultado apenas um dígito) que é passado para a função auxiliar que irá imprimí-lo 
	// len é somado a quantidade de caracteres impressos
		nb = nb - (nb / ten) * ten; //o número será agora o número sem sua casa mais alta (exemplo 534 fica 34)
		ten = ten / 10; //potência de dez perde uma casa
		//isso se repete até que todas as casas do número sejam convertidas para char	
	}
	return (len); // retornamos o tamanho da impressão
}

//função que recebe apenas ints positivos a partir do qual fará a "impressão" caracter a caracter
int	ft_put_u_nbr(unsigned int n)
{
	int	ten;  // int auxiliar que receberá a potência de 10 referente ao número;
	int	len;  // varíavel que receberá a quantidade de caracteres impressos

	len = 0;  // a quantidade de caracteres impressos inicia-se em zero
	ten = 1; // a quantidade de caracteres impressos inicia-se em zero
	while (ten <= n / 10)  // enquanto a potência de 10 tiver menos casas do que o número passado
		ten = ten * 10;  // multiplicamos essa potência por dez
	while (ten >= 1) // enquanto a potência de 10 for maior ou igual a 1
	{
		len += convert_char_int (n / ten); //número dividido pela potência de 10 (essa divisão fornece como
	// resultado apenas um dígito) que é passado para a função auxiliar que irá imprimí-lo 
	// len é somado a quantidade de caracteres impressos
		n = n - (n / ten) * ten; //o número será agora o número sem sua casa mais alta (exemplo 534 fica 34)
		ten = ten / 10; //potência de dez perde uma casa
		//isso se repete até que todas as casas do número sejam convertidas para char	
	}
	return (len); // retornamos o tamanho da impressão
}
