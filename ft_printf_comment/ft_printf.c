/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:55:48 by maclara-          #+#    #+#             */
/*   Updated: 2022/10/13 22:13:42 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf"
// essa funçao analisa o próximo caracter depois do % e  chama a funçao adequada para a impressao, assim
// cada tipo de argumento é impresso adequadamente, e como retorno ela dá o número de caracteres impressos
// As diretrizes da tarefa pedem que tratemos os seguintes tipos de argumentos: c,s,p,d,i,u,x,X, e %
static int	print_format(const char *fmt, int i, va_list args) // ela recebe a string digitada no printf,
// o índice que percorre a string e a lista de argumentos
{
	int len; // criamos uma variável para receber o tamanho que retornar das funções

	len = 0; // ela inicia zerada
	if (fmt[i] == 'c') // char
		len = ft_putchar(va_arg(args, int)); // len recebe o retorno da função que imprime um char
		// va_arg (lista, tipo_de_dado) retorna o parâmetro atual contido na variável "lista" e do tipo passado
	if (fmt[i] == 's')
		len = ft_putstr(va_arg(args, char *)); // len recebe o retorno da função que imprime uma string
	if (fmt[i] == 'p')
		len = ft_put_pt(va_arg(args, unsigned long)); // len recebe o retorno da função que imprime o ponteiro
	if (fmt[i] == 'd')
		len = ft_putnbr(va_arg(args, int)); // len recebe o retorno da função que imprime número com sinal,
		// maiores ou menores que zero
	if (fmt[i] == 'i')
		len = ft_putnbr(va_arg(args, int)); // len recebe o retorno da função que imprime qualquer inteiro
	if (fmt[i] == 'u')
		len = ft_put_u_nbr(va_arg(args, unsigned int)); // len recebe o retorno da função que imprime número
		// sem sinal, mas apenas números maiores que zero
	if (fmt[i] == 'x')
		len = ft_puthexa(va_arg(args, unsigned int)); // len recebe o retorno da função que imprime em 
		//hexa minúsculo
	if (fmt[i] == 'X')
		len = ft_puthexa_upper(va_arg(args, unsigned int)); // len recebe o retorno da função que
		//imprime em hexa maiúsculo
	if (fmt[i] == '%')
		len = ft_putchar('%'); // len recebe o retorno da função que imprime apenas um %
	return(len); // retornamos len, a quantidade de caracteres impressos
}

// esta função imprime a string passada para o printf, quando encontra um %_ ela chama a função acima...
// depois continua a impressão, e como retorno entrega um int referente a quantidade de caracteres impressos
static int	make_print_buffer(const char *fmt, va_list args) // recebemos a string e a lista de argumentos
{
	int	i; // criamos um int que será o índice que percorrerá a string
	int	len_str; // criamos uma variável que será o tamanho total da strins impressa

	i = 0;
	len_str = 0;
	while(fmt[i]) // enquanto a string existir
	{
		if (fmt[i] == '%') // se o caracter for %
		{
			len_str += print_format(fmt, i + 1, args); // len_str é somado com o retorno da função que avalia
			// o formato passado e cuidará da impressão do argumento ... passamos i + 1 pois queremos mandar o 
			// ínice do caracter que está logo depois do %
			i++; //avançamos uma casa para sairmos do %, e no fim dessa chave, avançaremos de novo, assim vamos
			// para o próximo caracter que deve ser observado
		}
		else // enqueanto não for um tipo (%_)
		{
			len_str += write(1, &fmt[i], 1); // usamos a função write para escrever enquanto armazenamos a
			// quantidade de caracteres impressos
		}
		i++; // avançamos para a próxima casa da string
	}
	return (len_str); // retornamos o tamanho completo da string escrira
}


// essa é a função principal :)
// é uma função variável ou em inglês 'Variadic function'. É uma função que tem sempre um primeiro argumento
// e pode ter muitos outros ou não ter nenhum outro, por isso o nome variável. 
// Para trabalhar com uma função variável usamos a biblioteca <stdarg.h>
int	ft_printf(const char *fmt, ...) //
{
	va_list	args; //va_list - tipo usado de parâmetro para as macros da biblioteca "stdarg.h", serve para //
	// recuperar os parâmetros adicionais da função
	int		printed; // essa variável irá armazenar a quantidade de caracteres que foram impressos

	va_start(args, fmt); //va_start (lista, ultimo_parametro) - inicializa a variável ]
	//do tipo lista (a va_lista) que eu criei, com as infos necessárias para recuperar os parâmetros adicionais
	printed = make_print_buffer(fmt, args); // printed recebe quantidade de caracteres que foram impressos da 
	// função que imprimirá a string passada e irá tratar dos tipos (%_) quando aparecerem 
	va_end(args); //va_end(lista) - macro para ser utilizada na finalização da função, serve para destruir a 
	// variável tipo lista e evitar problemas de memórias; (ela já da free na lista)
	return (printed); // a impressão já foi feita e o retorno é a quantidade de caracteres que foram impressos
}
