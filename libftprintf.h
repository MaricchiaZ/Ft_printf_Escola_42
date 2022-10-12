/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:55:53 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/12 02:08:55 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c);

int	ft_putstr(char *str);

int	ft_putnbr(int n);

int	ft_put_u_nbr(unsigned int n);

int ft_puthexa(unsigned int	n);

int ft_puthexa_upper(unsigned int n);

int	ft_printf(const char *fmt, ...);

#endif

// https://petbcc.ufscar.br/stdarg/
// Descrição da BIBLIOTECA <stdarg.h>:
// No cabeçalho encontram-se macros e tipos extremamente úteis, no que tange a criação 
// de funções para as quais a quantidade de argumentos não tem uma quantidade finita definida. 
// Assim, o cabeçalho <stdarg.h> é de muita valia com tais recursos, uma vez que o planejamento 
// de funções sem um número fixo de argumentos torna-se algo viável.

// Tipos:
// va_list: armazena os valores passados como argumento na função em que for declarado.
// Macros:
// va_start(va_list nTermos, ...): inicializa os n termos passado como argumento na função para 
// a variável nTermos.
// va_arg(va_list nTermos, tipo das variáveis passadas como argumento): percorre a lista dos argumentos na 
// ordem em que eles foram passados.
// va_end(va_list nTermos): deve ser chamada imediatamente antes da função em que as macros estão sendo 
// utilizadas retornar algum valor.


// typedef struct	s_print
// {
// 	va_list	args; //arg para imprimir
// 	int		wdt; //largura 
// 	int		prc; //precisão
// 	int		zero; //preenchimento zero
// 	int		pnt; // .
// 	int		dash; // -
// 	int		tl; // total_length (valor de retorno)
// 	int		sign; // sinal de positivo ou negativo
// 	int		is_zero; // é o número zero
// 	int		perc; //%
// 	int		sp; //sinalizador de espaço ' '
// }	t_print;