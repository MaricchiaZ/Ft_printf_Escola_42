/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:55:44 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/28 18:13:07 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

https://iq.opengenus.org/how-printf-and-scanf-function-works-in-c-internally/




*/