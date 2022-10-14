/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:55:53 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 22:28:22 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H // se não existir a biblioteca ft_printf.h
# define FT_PRINTF_H // criamos aqui

#include <stdarg.h> // biblioteca do va_start, va_arg, va_copy, va_end
#include <unistd.h> // para a função write
#include <stdlib.h> // para a função malloc

int		ft_putchar(char c); // aqui estão os protótipos das funções que compõe a biblioteca

int		ft_putstr(char *str);

int		ft_putnbr(int n);

int		ft_put_u_nbr(unsigned int n);

int		ft_puthexa(unsigned int	n);

int		ft_puthexa_upper(unsigned int n);

int		ft_put_pt(unsigned long n);

void	*ft_calloc(size_t nmemb, size_t size);

int		ft_printf(const char *fmt, ...);

#endif // aqui finaliza-se as declarações da biblioteca
