# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 17:59:59 by mlitvino          #+#    #+#              #
#    Updated: 2024/11/22 15:31:15 by mlitvino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = \
	ft_printf.c ft_putchar.c ft_puthex.c  ft_putint.c ft_putptr.c ft_putstr.c ft_putu.c
BSRC = \

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
DEPS = ft_printf.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	$(AR) -rcs $@ $^

.SECONDARY: $(OBJ) 

%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJ) $(BOBJ) .BONUS_DEPEND

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
