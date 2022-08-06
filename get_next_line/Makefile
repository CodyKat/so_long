CC = cc
NAME = gnl.a
CFLAGS = -Wall -Wextra -Werror
DEFINE = -D BUFFER_SIZE=1
LIBFT = ../libft/libft.a
SRCS = get_next_line.c			\
	   get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

all : ${LIBFT} ${NAME}

$(NAME) : ${OBJS}
	ar rsv ${NAME} ${OBJS}

${LIBFT} :
	make -C ../libft/ all

clean :
	rm -f ${OBJS}; rm -f ${LIBFT}

fclean : clean
	rm -f ${NAME}

.PHONY : all clean fclean bonus re

re : fclean all
