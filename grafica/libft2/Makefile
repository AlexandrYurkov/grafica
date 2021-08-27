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

SRCS =	ft_gnl.c ft_putchar_fd.c ft_putstr_fd.c ft_split.c ft_strcat.c ft_strchr.c \
ft_strclr.c ft_strcpy.c ft_strlcpy.c ft_strdel.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_strsub.c \
ft_words_count.c ft_error.c ft_atoi.c\


FLAGS = -Wall -Wextra -Werror

OPTF = -O2

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