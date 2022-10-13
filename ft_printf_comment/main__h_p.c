/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:35:16 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 13:51:15 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    int i = 123456;
    int j = 89364284;
    int k = 0;
    int l = 123;
    int m = 15;
    
    char    *p;
    char    *p1;
    char    *p2; 
    char    *p3; 
    char    *p4; 
    
    ft_printf("i = 123456 em hexa = %x\n", i);
    ft_printf("j = 89364284 em hexa = %x\n", j);
    ft_printf("k = 0 em hexa = %x\n", i);
    ft_printf("l = 123 em hexa = %x\n", i);
    ft_printf("m = 15 em hexa = %x\n\n", i);

    ft_printf("i = 123456 em HEXA = %X\n", i);
    ft_printf("j = 89364284 em HEXA = %X\n", j);
    ft_printf("k = 0 em HEXA = %X\n", i);
    ft_printf("l = 123 em HEXA = %X\n", i);
    ft_printf("m = 15 em HEXA = %X\n\n", i);

    p = "abacate";
    p1 = "a";
    p2 = ""; 
    p3 = ((void *) 0); 
    p4 = "minions";
    
    ft_printf("p = abacate, end do ponteiro = %p\n", p);
    ft_printf("p1 = a, end do ponteiro = %p\n", p1);
    ft_printf("p2 = , end do ponteiro = %p\n", p2);
    ft_printf("p3 = ((void *) 0), end do ponteiro = %p\n", p3);
    ft_printf("p4 = minions, end do ponteiro = %p\n", p4);    
}