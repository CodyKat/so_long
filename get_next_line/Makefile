CC = cc
NAME = gnl.a
CFLAGS = -Wall -Wextra -Werror
DEFINE = -D BUFFER_SIZE=1
LIBFT = libft.a
SRCS = get_next_line.c			\
	   get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

$(NAME) : ${OBJS}
	cd ../libft; make; mv libft.a ../get_next_line;	cd ../get_next_line;	\
		ar rsv ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}; rm -f ${LIBFT}

fclean : clean
	rm -f ${NAME}

.PHONY : all clean fclean bonus re

re : fclean all
