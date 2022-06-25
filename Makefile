# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 12:12:15 by kalmheir          #+#    #+#              #
#    Updated: 2022/06/25 13:13:03 by kalmheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft.a
MANDSDIR	:= src/general
PRINTFDR	:= src/ft_printf
ADTDIR		:= src/data_structures
SRCDIRS		:= $(MANDSDIR) $(PRINTFDR) $(ADTDIR)
SOURCES		:= $(shell find $(SRCDIRS) -name '*.c')
MLXUTILS	:= $(shell find src/mlx -name '*.c')
MLXUOBJS	:= $(MLXFLAGS) $(MLXUTILS:.c=.o)
OBJECTS		:= $(SOURCES:.c=.o)
LIBC		:= ar rcs
CC			:= gcc
RM			:= rm -f
CFLAGS		:= -Wall -Wextra -Werror
MLXFLAGS	:= -Imlx

nomlxc: nomlx clean

$(NAME): nomlx

nomlx: $(OBJECTS)
	$(LIBC) $(NAME) $(OBJECTS)

allc: all clean

all: $(NAME) $(OBJECTS) $(MLXUOBJS)
	$(LIBC) $(NAME) $(OBJECTS) $(MLXUOBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


clean:
	$(RM) $(OBJECTS)
	$(RM) $(MLXUOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean nomlx

rea: fclean all
