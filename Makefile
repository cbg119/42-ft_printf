# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbagdon <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/23 18:04:52 by cbagdon           #+#    #+#              #
#    Updated: 2019/03/01 14:17:52 by cbagdon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

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
				  convert_xl.c \
				  convert_percent.c

SRCS = ft_printf.c \
	   decision.c \
	   options.c \
	   utils.c

LIBFT_SRCS = ft_strcpy.c \
       ft_strdup.c \
       ft_strlen.c \
       ft_strncpy.c \
       ft_strcat.c \
       ft_strncat.c \
       ft_strlcat.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strstr.c \
       ft_strnstr.c \
       ft_strcmp.c \
       ft_strncmp.c \
       ft_atoi.c \
       ft_isalpha.c \
       ft_isdigit.c \
       ft_isupper.c \
       ft_islower.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_toupper.c \
       ft_tolower.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memccpy.c \
       ft_memmove.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_memalloc.c \
       ft_memdel.c \
       ft_strnew.c \
       ft_strdel.c \
       ft_strclr.c \
       ft_striter.c \
       ft_striteri.c \
       ft_strmap.c \
       ft_strmapi.c \
       ft_strequ.c \
       ft_strnequ.c \
       ft_strsub.c \
       ft_strjoin.c \
       ft_strtrim.c \
       ft_getwordcount.c \
       ft_strsplit.c \
       ft_intlen.c \
       ft_itoa.c \
       ft_putchar.c \
       ft_putstr.c \
       ft_putendl.c \
       ft_putnbr.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
       ft_lstnew.c \
       ft_lstdelone.c \
       ft_lstdel.c \
       ft_lstadd.c \
       ft_lstiter.c \
       ft_lstpush.c \
       ft_lstmap.c \
       ft_strccpy.c \
       get_next_line.c \
       ft_strndup.c \
       ft_stroverlap.c \
       ft_strmove.c \
       ft_strrev.c

INCLUDES = includes/ft_printf.h \
		   includes/libft.h \
		   includes/get_next_line.h

OBJECTS = $(patsubst %.c,%.o,$(SRCS))
OBJECTS += $(patsubst %.c,%.o,$(CONVERSION_SRCS))
OBJECTS += $(patsubst %.c,%.o,$(EXTRA_SRCS))
OBJECTS += $(patsubst %.c,%.o,$(LIBFT_SRCS))

all: $(NAME)

$(NAME):
	gcc -g -Wall -Wextra -Werror -c $(addprefix src/,$(SRCS)) $(addprefix extras/,$(EXTRA_SRCS)) $(addprefix conversions/,$(CONVERSION_SRCS)) $(addprefix libft/,$(LIBFT_SRCS)) -I $(INCLUDES)
	ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
