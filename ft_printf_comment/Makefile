SRCS	= ft_printf.c ft_printf_utils.c print_char_str.c print_nbrs.c print_hexa.c print_pt.c #aqui contém 
#todos os nomes dos arquivos que formarão a biblioteca 

HEADERS	= ./ft_printf.h # indica que o cabeçalho está nessa mesma pasta (./), no arquivo ft_printf.h

OBJS	= ${SRCS:.c=.o} #os objetos serão formados por o que existe em SRCS, mantendo o nome
# mas trocando o .c por .o

NAME	= libftprintf.a   # o nome para a biblioteca criada será libftprintf.a

RM	= rm -f # para remover, usaremos rm com -f (force), ignora ficheiros e argumentos inexistentes

.c.o: # faz um arquivo.o a partir de um arquivo.c é a mesma coisa que:  %.o: %.c 
# os arquivos-fonte que compõem a biblioteca devem ser compilados, para gerar os arquivos-objeto 
# correspondentes
# é complilado usando o compilador gcc e usamos as flags
# -Wall -Wextra -Werror, possibilita os avisos
# -c a opção diz para não executar o linker, então ela forma os .o, objetos produzidos pelo assembler.
# $< pega o que está a direita da regra, no caso .c e passa para a esquerda
# -o orienta o output ${<:.c=.o} esse padrão indica que mantém-se os nomes apenas trocando .c para .o
# o @ não deixa a regra aparecer na linha de comando quando o make estiver rodando
# -Wall -Wextra -Werror
	clang -Wall -Wextra -Werror  -g -c $< -o ${<:.c=.o} 

all: ${NAME} # all: É o nome das regras a serem executadas

${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean: # -Apaga os arquivos intermediários. Se você escrever make clean no terminal
# -usamos as rediretrizes de RM para remover os objetos da srcs e os objetos do bonus
# o @ não deixa a regra aparecer na linha de comando quando o make estiver rodando
	${RM} ${OBJS} ${BONUS_OBJS} 

fclean:	clean #-realiza a regra clean
# -e remove também o nome
# o @ não deixa a regra aparecer na linha de comando quando o make estiver rodando
	${RM} ${NAME} 

re: fclean all #-deleta e recomplila tudo (se mexermos em algum arquivo podemos dar make re)

.PHONY:	all clean fclean re # -Esta regra permite de evitar conflitos. é uma proteção, se tiver 
# um arqiuvo com o mesmo nome de uma das regras, a regra deve ser executada, mesmo se existirem 
# arquivos com o nome dela.

# significado dos símbolos
 #   $@    Nome da regra. 
 #   $<    Nome da primeira dependência 
 #   $^ 	Lista de dependências
 #   $? 	Lista de dependências mais recentes que a regra.
 #   $* 	Nome do arquivo sem sufixo