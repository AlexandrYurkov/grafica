# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfallon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/08 15:31:26 by lfallon           #+#    #+#              #
#    Updated: 2021/05/08 16:32:58 by lfallon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = ./

HEADER = libft.h

SRCS =	ft_atoi.c get_next_line.c ft_lstadd.c ft_lstnew.c ft_matfree.c ft_memcpy.c \
	ft_memdel.c ft_memset.c ft_memset.c ft_split.c ft_strdup.c ft_strjoin.c \
	ft_strdel.c ft_words_count.c ft_strnew.c ft_strchr.c ft_strsub.c ft_strlen.c \
	ft_strcpy.c ft_realloc.c \


FLAGS = -Wall -Wextra -Werror -g


OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c 
	gcc -c $(FLAGS) -I $(INCLUDES) -o $@ $<

clean: 
	rm -f $(OBJ) $(BONUS_O)

fclean: clean
	rm -f $(NAME)

re: fclean all bonus clean

.PHONY: all clean fclean re bonus