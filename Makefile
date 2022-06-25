# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 12:12:15 by kalmheir          #+#    #+#              #
#    Updated: 2022/06/25 12:26:59 by kalmheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a
MANDSDIR	:= src/mandatory
PRINTFDR	:= src/ft_printf
ADTDIR		:= src/data_structures
SRCDIRS		:= $(LIBCCOPY) $(LIBCNEWS) $(PRINTFDR) $(ADTDIR)
SOURCES		:= $(shell find $(SRCDIRS) -name '*.c')
MLXUTILS	:= $(shell find src/mlx -name '*.c')
MLXUOBJS	:= $(MLXUTILS:.c=.o)
OBJECTS		= $(SOURCES:.c=.o)
LIBC	= ar rc
LIBR	= ranlib
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

nomlx: $(OBJECTS)


all: $(OBJECTS) $(MLXUOBJS)

$(OBJECTS):
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$()

$(LBFT): $(OBJS)
	$(LIBC) $(LBFT) $(OBJS)
	$(LIBR) $(LBFT)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LBFT)
	$(RM) $(PGRM)

re: fclean all
