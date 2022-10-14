/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:11:14 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 21:17:16 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// essa função zera/limpa/coloca byte nulo/ coloca '\0' uma área da memória
static void	ft_bzero(void *s, int n) //recebe um ponteiro pra uma área da memória e o número de bytes q deve limpar
{
	int	i; //índice auxiliar para percorrer a memória

	i = 0; //índice começa no 0
	while (n && s) //enquanto a string s e o n forem verdadeiros, existirem, ou seja, não forem nulos
	{
		*(unsigned char *)(s + i) = '\0'; //fazemos um cast do ponteiro void de s para um ponteiro unsigned char
		// e somamos o s ao índice, fazendo uma aritmérica de ponteiro, 
		//e  cada byte que passamos recebe o byte nulo '\0' 
		n--; //decrementamos o n para agir apenas nos n bytes pedidos
	}
}

void	*ft_calloc(size_t nmemb, size_t size) //recebe o número de membros e o tam de cada um
{
	size_t	aux; //variável aux
	void	*tab; //ponteiro para a memória que alocaremos

	if (nmemb == 0) // se número de membros for 0, retornamos NULL
		return (NULL);
		// se número de membros ou o size, ou a multiplicação dos dois for maior que o size_t max, retornamos NULL
	if (nmemb > 2147483647 || size > 2147483647 || size * nmemb > 2147483647)
		return (NULL);
	aux = (size) * (nmemb); //aux armazena a quantidade de bytes referente a n membros de tamanho size
	tab = malloc(aux); //nosso ponteiro recebe a malocação da quantidade de bytes
	if (tab == NULL) // se o malloc der errado, tab será igual a NULL
		return (NULL); // então retornamos NULL
	ft_bzero(tab, aux); // caso a malocação tenha dado certo "zeramos" a memória dos i bytes
	return (tab); //retornamos nosso ponteiro para os bytes alocados e "limpos"
}
