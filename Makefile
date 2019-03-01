# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/23 18:04:52 by cbagdon           #+#    #+#              #
#    Updated: 2019/02/28 23:45:21 by cbagdon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

EXTRA_SRCS = ft_intmove.c \
			 ft_pad.c \
			 ft_numlen.c

CONVERSION_SRCS = convert_s.c \
				  convert_i.c \
				  convert_c.c \
				  convert_p.c \
				  convert_o.c \
				  convert_u.c \
				  convert_x.c \
				  convert_X.c \
				  convert_percent.c

SRCS = ft_printf.c \
	   decision.c \
	   options.c \
	   utils.c

OBJECTS = $(patsubst %.c,%.o,$(SRCS))
OBJECTS += $(patsubst %.c,%.o,$(CONVERSION_SRCS))
OBJECTS += $(patsubst %.c,%.o,$(EXTRA_SRCS))

all: $(NAME)

$(NAME):
	make -C libft
	gcc -g -Wall -Wextra -Werror -c $(addprefix src/,$(SRCS)) $(addprefix extras/,$(EXTRA_SRCS)) $(addprefix conversions/,$(CONVERSION_SRCS)) -I includes/ft_printf.h
	gcc -g -Wall -Wextra -Werror -o $(NAME) $(OBJECTS) -L ./libft/ -lft

clean:
	make -C libft clean
	rm -rf $(OBJECTS)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
