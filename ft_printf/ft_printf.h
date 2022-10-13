/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:55:53 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 12:38:32 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putchar(char c);

int		ft_putstr(char *str);

int		ft_putnbr(int n);

int		ft_put_u_nbr(unsigned int n);

int		ft_puthexa(unsigned int n);

int		ft_puthexa_upper(unsigned int n);

int		ft_put_pt(unsigned long n);

void	*ft_calloc(size_t nmemb, size_t size);

int		ft_printf(const char *fmt, ...);

#endif
