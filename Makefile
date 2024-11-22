# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 17:59:59 by mlitvino          #+#    #+#              #
#    Updated: 2024/11/19 18:00:00 by mlitvino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = \
	ft_printf.c ft_putchar.c ft_puthex.c  ft_putint.c ft_putptr.c ft_putstr.c ft_putu.c 
BSRC = \

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) -rcs $@ $^

bonus: $(NAME) .BONUS_DEPEND

.BONUS_DEPEND : $(BOBJ) $(OBJ)
	$(AR) -rcs $(NAME) $(BOBJ) $(OBJ)
	touch .BONUS_DEPEND

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJ) $(BOBJ) .BONUS_DEPEND

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
