
# ft_printf 

### Descrição da tarefa: 
Escreva uma biblioteca que contenha ft_printf(), a função que irá imitar a printf() original.

### Nome do programa que devemos fazer: libftprintf.a

Arquivos que devemos enviar: Makefile, *.h, */*.h, *.c, */*.c (e qualquer outro arquivo necessário)

### Funções autorizadas: malloc, free, write,\
va_start, va_arg, va_copy, va_end

### LIBFT:\ Autorizada

### RETORNO: um int como tamanho da string impressa;

### O protótipo da sua função ft_printf() deve ser: \
int	ft_printf(const char *, ...);

### Você tem que implementar as seguintes conversões: \
- %c imprime um único caractere.\
- %s imprime uma string (como definido pela convenção C comum).\
- %p O argumento do void * ponteiro tem que ser impresso em formato hexadecimal. \
- %d imprime um número decimal (base 10).\
- %i imprime um número inteiro na base 10.\
- %u imprime um número decimal unsigned (base 10).\
- %x imprime um número em formato hexadecimal minúsculo (base 16) .\
- %X imprime um número em hexadecimal (base 16), no formato de letras maiúsculas.\
- %% imprime um sinal de porcentagem.\

______________________________________________________________________________________________________________

## Funções Variáveis: 

Em matemática e em programação de computadores, uma função variada é uma função de indefinição, ou seja,\
 aquela que aceita um número variável de argumentos.

Uma das funções variáveis mais famosas é a printf "int printf (const char *format, ...)".

Para usar uma função variável podemos usar a biblioteca <stdarg.h>, nela existe a va_liste outras funções\
que faciliram usar os parâmetros que podem ou não existir, e se existirem, podem existir em qualquer quantidade :)

Aqui está uma pequena explicação das funções que iremos usar: 

*va_list* - tipo usado de parâmetro para as macros da biblioteca "stdarg.h", serve para recuperar os\ 
parâmetros adicionais da função

*va_start (lista, ultimo_parametro)* - inicializa a variável do tipo lista (a va_lista) que eu criei, \
com as infos necessárias para recuperar os parâmetros adicionais

*va_arg (lista, tipo_de_dado)* - retorna o parâmetro atual contido na variável "lista" e do tipo "va_list"

A lista foi inicializada e dentro dela tem todos os parâmetros que foram passados, então usaremos assim:
'x = va_arg(lista, float);'  assim acessamos o próximo parâmetro, da lista, convertido pra float e \
 salvamos no x;

*va_end(lista)* - macro para ser utilizada na finalização da função, serve para destruir a variável \
tipo lista e evitar problemas de memórias; 

______________________________________________________________________________________________________________

## Descrição da BIBLIOTECA <stdarg.h>

retirado de: https://petbcc.ufscar.br/stdarg/

No cabeçalho encontram-se macros e tipos extremamente úteis, no que tange a criação 
de funções para as quais a quantidade de argumentos não tem uma quantidade finita definida. 
Assim, o cabeçalho <stdarg.h> é de muita valia com tais recursos, uma vez que o planejamento 
de funções sem um número fixo de argumentos torna-se algo viável.

Tipos:
va_list: armazena os valores passados como argumento na função em que for declarado.
Macros:
va_start(va_list nTermos, ...): inicializa os n termos passado como argumento na função para 
a variável nTermos.
va_arg(va_list nTermos, tipo das variáveis passadas como argumento): percorre a lista dos argumentos na 
ordem em que eles foram passados.
va_end(va_list nTermos): deve ser chamada imediatamente antes da função em que as macros estão sendo 
utilizadas retornar algum valor.
______________________________________________________________________________________________________________

## A função printf original: 

Aqui está a versão GNU de printf... você pode vê-la passando stdoutpara vfprintf:

__printf (const char *format, ...)
{
   va_list arg;
   int done;

   va_start (arg, format);
   done = vfprintf (stdout, format, arg);
   va_end (arg);

   return done;
}