SRCS	= ft_printf.c ft_printf_utils.c print_char_str.c print_nbrs.c print_hexa.c print_pt.c 

HEADERS	= ./ft_printf.h 

OBJS	= ${SRCS:.c=.o}

BONUS_OBJS	= ${BONUS:.c=.o}

NAME	= libftprintf.a

RM	= rm -f

.c.o:
	clang -Wall -Wextra -Werror -g -c $< -o ${<:.c=.o} 

all: ${NAME}

${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS} ${BONUS_OBJS} 

fclean:	clean
	${RM} ${NAME} 

re: fclean all

.PHONY:	all clean fclean re
