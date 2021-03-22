# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouseqqam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 13:50:23 by ouseqqam          #+#    #+#              #
#    Updated: 2019/07/24 09:29:06 by ouseqqam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = fillit
FLAGS = -Wall -Werror -Wextra
FILE  = ft_check_suite.c \
	    ft_check.c \
	    move_to_up.c \
	    set.c \
		ft_print_words_tables.c \
		ft_putendl.c \
		ft_strjoin.c \
		ft_strnew.c \
		ft_putchar.c \
		ft_strlen.c \
		ft_bzero.c \
		main.c \

SRC = $(FILE:.c=.o)

all:$(NAME)

$(NAME): $(SRC)
	      @gcc $(FLAGS) -o fillit  $(FILE)  -I fillit.h

%.o: %.c
		  @gcc $(FLAGS) -c $<

clean:
	      @rm -f $(SRC)

fclean: clean
	      @rm -f $(NAME)

re: fclean all
