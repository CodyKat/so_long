CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I mlx
LFLAGS = -L mlx -lmlx -framework OpenGL -framework AppKit
GNLFT = ./get_next_line/gnl.a
LIBFT = ./libft/libft.a
MLX_LIB = ./mlx/libmlx.a
SRCS = main_bonus.c					\
	   control_bonus.c				\
	   enemy_control1_bonus.c		\
	   enemy_control2_bonus.c		\
	   error_bonus.c				\
	   error_2_bonus.c				\
	   get_map_bonus.c				\
	   render_bonus.c

OBJS = ${SRCS:.c=.o}

%.o:%.c
	$(CC) $(IFLAGS) $(CFLAGS) -o $@ -c $<

all : ${NAME}

$(NAME) : ${LIBFT} $(GNLFT) ${OBJS} ${MLX_LIB}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LFLAGS} ${GNLFT} ${LIBFT}

bonus : all

$(LIBFT) :
	make -C ./libft/ all

$(GNLFT) :
	make -C ./get_next_line/ all

$(MLX_LIB) :
	make -C ./mlx/ all

mlx_compile :
	make -C ./mlx/ all

clean_gnl :
	make -C ./get_next_line/ clean

clean_libft :
	make -C ./libft/ clean

clean_mlx :
	make -C ./mlx/ clean

clean : fclean_gnl fclean_libft clean_mlx
	rm -f ${OBJS}



fclean_gnl :
	make -C ./get_next_line/ fclean

fclean_libft :
	make -C ./libft/ fclean

fclean : clean
	rm -f ${NAME}

.PHONY : all clean fclean bonus re

re : fclean all
