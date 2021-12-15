NAME	=	fractol

SRCS_DIR	=	srcs/

SRCS_FILES	=	main.c \
				utils.c \
				help.c \
				mandelbrot.c \
				colors.c \
				events.c \
				julia.c \
				mlx_init.c \
				libft.c \
				burnship.c

OBJS	=	${addprefix ${SRCS_DIR}, ${SRCS_FILES:.c=.o}}

HEAD	=	-I includes -I mlx

CC	=	clang

CFLAGS	=	-Wall -Werror -Wextra

MLX_DIR	=	mlx

LIBFT_DIR = libft

LIB_FLAGS=	-L ${MLX_DIR}

MLX_FLAGS=	-lm -lmlx -lXext -lX11

DEFINE_DEFAULT=	-D PROJECT_NAME="${NAME}"

.o:.c
	${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C ${MLX_DIR}
			${CC} ${CFLAGS} ${LIB_FLAGS} ${HEAD} ${DEFINE_DEFAULT} ${OBJS} -o ${NAME} ${MLX_FLAGS}

all:			${NAME}

bonus:			${NAME}

clean:
		rm -rf ${OBJS}
		make clean -C ${MLX_DIR}

fclean: clean
		rm	-rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
