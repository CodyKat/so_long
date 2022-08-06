CC = gcc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_strjoin.c	\
	   ft_strlcpy.c	\
	   ft_strncmp.c	\
	   ft_split.c	\
	   ft_strlcat.c	\
	   ft_strlen.c	\
	   ft_itoa.c

OBJS = ${SRCS:.c=.o}

OBJ_FILES = ${OBJS}

all : ${NAME}

$(NAME) : ${OBJ_FILES}
	ar rs ${NAME} ${OBJ_FILES}

clean :
	rm -f ${OBJS} ${OBJS_BONUS}

fclean : clean
	rm -f ${NAME}

.PHONY : all clean fclean bonus re

re : fclean all
