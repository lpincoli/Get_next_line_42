# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpincoli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 15:38:56 by lpincoli          #+#    #+#              #
#    Updated: 2022/10/13 15:32:25 by lpincoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = get_next_line.a

BUFF = -D BUFFER_SIZE=1

SRC :=	get_next_line.c \
	get_next_line_utils.c \

OBJ_S = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_S)
	ar -rcs $@ $^

%.o:%.c
	@$(CC) -c $(CFLAG) $(BUFF) -I.  $< -o $@

clean: 
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

faitutto: re
	clear
	$(CC) $(CFLAG) main.c get_next_line.a
	./a.out

.PHONY: all clean fclean re
