/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:55:44 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 11:06:42 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_char_int(int n)
{
	char	c;

	c = '0';
	c = c + n;
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int n)
{
	int			ten;
	long int	nb;
	int			len;

	nb = n;
	ten = 1;
	len = 0;
	if (nb < 0)
	{
		len +=write(1, "-", 1);
		nb = nb * -1;
	}
	while (ten <= nb / 10)
		ten = ten * 10;
	while (ten >= 1)
	{
		len += convert_char_int (nb / ten);
		nb = nb - (nb / ten) * ten;
		ten = ten / 10;
	}
	return (len);	
}

int	ft_put_u_nbr(unsigned int n)
{
	int	ten;
	int	len;

	len = 0;
	ten = 1;
	while (ten <= n / 10)
		ten = ten * 10;
	while (ten >= 1)
	{
		len += convert_char_int (n / ten);
		n = n - (n / ten) * ten;
		ten = ten / 10;
	}
	return (len);	
}

// Funções externas permitidas: malloc, free, write, va_start, va_arg, va_copy, va_end

// Permissão para usar a Libft: SIM

// Diretrizes da tarefa: Escreva uma biblioteca que contenha ft_printf(), sua função 
// deve irá imitar a printf original()

/* Aqui estão as exigências:
- Não implemente o gerenciamento do buffer da impressão original().
- Sua função tem que lidar com as seguintes conversões: cspdiuxX%
- Sua função será comparada com a original printf().
- Você deve usar o comando ar para criar sua biblioteca.
O uso do comando libtool é proibido.
- Sua libftprintf.a tem que ser criada na raiz de seu repositório.

Você tem que implementar as seguintes conversões:
- %c imprime um único caractere.
- %s Imprime uma cadeia (como definido pela convenção C comum).
- %p O argumento do vazio * ponteiro tem que ser impresso em formato hexadecimal. - %d imprime um número decimal (base 10).
- %i Imprime um número inteiro na base 10.
- %u Imprime um número decimal não assinado (base 10).
- %x imprime um número em formato hexadecimal (base 16) minúsculas.
- %X imprime um número em hexadecimal (base 16) formato de letras maiúsculas.
- %% imprime um sinal de porcentagem.

*/

/*
Base de apoio:

https://www.geeksforgeeks.org/variadic-functions-in-c/

https://iq.opengenus.org/how-printf-and-scanf-function-works-in-c-internally/

Funções variadicas são funções que podem receber um número variável de argumentos, ela adiciona flexibilidade ao programa. 
A função variádica tem um argumento fixo e, em seguida, qualquer número de argumentos pode ser passado. 
A função variádica consiste em pelo menos uma variável fixa e depois uma reticência(…) como último parâmetro.

Os valores dos argumentos passados ​​podem ser acessados ​​através do arquivo de cabeçalho denominado como:
#include <stdarg.h>


*/