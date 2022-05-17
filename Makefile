CC = cc
NAME = solong
CFLAGS = -g -Wall -Wextra -Werror
LFLAGS = -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit
GNLFT = gnl.a
LIBFT = libft.a
SRCS = main.c					\
	   control.c				\
	   enemy_control1.c			\
	   enemy_control2.c			\
	   error.c					\
	   error_2.c				\
	   get_map.c				\
	   render.c

OBJS = ${SRCS:.c=.o}

all : ${NAME}

$(NAME) : ${OBJS}
	cd get_next_line; make; cp ${GNLFT} ${LIBFT} ../; cd ../;		\
	${CC} ${CFLAG} -o ${NAME} ${OBJS} ${LFLAGS} ${GNLFT} ${LIBFT}

clean_gnl :
	cd get_next_line; make clean

clean_libft :
	cd libft; make clean

clean : fclean_gnl clean_libft
	rm -f ${OBJS}; rm -f ${LIBFT} ${GNLFT}


fclean_gnl :
	cd get_next_line; make fclean

fclean_libft :
	cd libft; make fclean

fclean : clean clean_gnl clean_libft fclean_gnl fclean_libft
	rm -f ${NAME}

bonus :
	make all

.PHONY : all clean fclean bonus re

re : fclean all
