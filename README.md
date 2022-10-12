
Descrição da tarefa: 
Escreva uma biblioteca que contenha ft_printf(), a
função que irá imitar a printf() original.

Nome do programa que devemos fazer: libftprintf.a

Arquivos que devemos enviar: Makefile, *.h, */*.h, *.c, */*.c (e qualquer outro arquivo necessário)

Funções autorizadas: malloc, free, write,
va_start, va_arg, va_copy, va_end

LIBFT: Autorizada

RETORNO: um int como tamanho da string impressa;

O protótipo da sua função ft_printf() deve ser: 
int	ft_printf(const char *, ...);

Você tem que implementar as seguintes conversões:
- %c imprime um único caractere.
- %s imprime uma string (como definido pela convenção C comum).
- %p O argumento do void * ponteiro tem que ser impresso em formato hexadecimal. 
- %d imprime um número decimal (base 10).
- %i imprime um número inteiro na base 10.
- %u imprime um número decimal unsigned (base 10).
- %x imprime um número em formato hexadecimal minúsculo (base 16) .
- %X imprime um número em hexadecimal (base 16), no formato de letras maiúsculas.
- %% imprime um sinal de porcentagem.


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




Um exemplo é retirado do livro "Linguagem C". Livro escrito por Brian Kernighan e Dennis Ritchie. Lá você encontrará explicações detalhadas da linguagem C e outras funções padrão.

#include <stdarg.h>

void minprintf(char *fmt,...)
{
    va_list ap; 
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for(p = fmt; *p; p++) {
        if(*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival );
                break;
            case 'f':
                dval  = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for(sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); 
}


    _Check_return_opt_
_CRT_STDIO_INLINE int __CRTDECL printf(
    _In_z_ _Printf_format_string_ char const* const _Format,
    ...)
#if defined _NO_CRT_STDIO_INLINE
;
#else
{
    int _Result;
    va_list _ArgList;
    __crt_va_start(_ArgList, _Format);
    _Result = _vfprintf_l(stdout, _Format, NULL, _ArgList);
    __crt_va_end(_ArgList);
    return _Result;
}
#endif

printf


https://github.com/torvalds/linux/blob/master/arch/x86/boot/printf.c



va_list - tipo usado de parâmetro para as macros
da i "stdarg.h", serve para recuperar os parâmetros
adicionais da função

va_start (lista, ultimo_parametro) - inicializa a variável
do tipo lista (a va_lista) que eu criei, com as infos
necessárias para recuperar os parâmetros adicionais

va_arg (lista, tipo_de_dado) - retorna o parâmetro atual 
contido na variável "lista" e do tipo "va_list"

A lista foi inicializada e dentro dela tem todos os parâmetros
que foram passados, então usaremos assim:
x = va_arg(lista, float);
pega o próximo parâmetro da lista, converte pra float e salva no x;

va_end(lista) - macro para ser utilizada na finalização
da função, serve para destruir a variável tipo lista
e evitar problemas de memórias; 
