SOURCE	=	main.c map_print.c map_read.c free_struct.c \
		pixel_put.c point_map.c trafiic_key.c \

HEADER	=	fdf.h libft/libft.h

OBJECTS	=	${SOURCE:.c=.o}

RM		=	rm -f

NAME	=	fdf.a

AR		=	ar rcs

CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c ${HEADER}
			gcc  -Ilibft -c $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
			make -C libft
			cp libft/libft.a $(NAME)
			${AR} ${NAME} ${OBJECTS}


all:		${NAME}

clean:
			make clean -C libft
			${RM} ${OBJECTS}

fclean:		clean
			make fclean -C libft
			${RM} ${NAME} *.out.dSYM

re:			fclean all

debug:		re
			gcc -g  *.c ./libft/libft.a

.PHONY:		all clean fclean bonus debug