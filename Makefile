NAME		=	cub3d
SRCS		=	cub3d_calcul1.c cub3d_calcul5.c cub3d_mouvement2.c cub3d_utils4.c parsing_utils3.c cub3d_calcul2.c cub3d_drawing1.c cub3d_utils1.c parsing_utils4.c cub3d.c cub3d_calcul3.c cub3d_drawing2.c cub3d_utils2.c parsing_utils1.c cub3d_calcul4.c cub3d_mouvement1.c cub3d_utils3.c parsing_utils2.c cub3d_utils5.c
OBJS		=	${SRCS:.c=.o}

CC			=	gcc

MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

all:			${NAME}

$(NAME):		${OBJS}
				${CC} -o ${NAME} ${OBJS} ${CFLAGS} ${MLXFLAGS} 
clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all