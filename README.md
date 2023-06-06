# Ft_printf_Escola_42

Este é o projeto ft_printf da Escola42, que tem como objetivo recriar a função printf da biblioteca padrão C.
O projeto consiste em implementar uma versão simplificada da função printf, capaz de formatar e imprimir dados na saída padrão de acordo com especificadores de formato.

## Sobre o Projeto
O projeto ft_printf é um exercício desafiador que permite praticar a manipulação de strings, argumentos variáveis e a formatação de saída.
A função ft_printf é amplamente utilizada em programação C para imprimir informações formatadas na tela ou em um arquivo.

## Funcionalidades
- Suporte aos especificadores de formato: %s, %c, %d, %i, %u, %x, %X, %p
- Suporte a argumentos variáveis

## Requisitos
- Conhecimento avançado de programação em C
- Compilador de C (GCC)
- Acesso a um ambiente UNIX (Linux ou macOS)

## Instalação e Uso
1. Clone este repositório em seu computador.
```bash
git clone https://github.com/MaricchiaZ/Ft_printf_Escola_42/ft_printf_comment
```
2. Entre no diretório do projeto.
```bash
cd Ft_printf_Escola_42/ft_printf_comment
```
3. Compile o código
```bash
make
```
4. Execute o programa rodando o main.c teste.
```bash
gcc main.c
```

## Como Usar
Inclua o arquivo ft_printf.h em seu código para ter acesso à função ft_printf.
Chame a função ft_printf passando uma string de formato e argumentos adicionais.
A função imprimirá a saída formatada de acordo com os especificadores de formato fornecidos.

## Especificadores de Formato Suportados
- %c - caractere
- %s - string
- %d ou %i - inteiro
- %u - inteiro sem sinal
- %x ou %X - inteiro em formato hexadecimal
- %p - ponteiro
