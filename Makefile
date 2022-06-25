# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kalmheir <kalmheir@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 12:12:15 by kalmheir          #+#    #+#              #
#    Updated: 2022/06/12 15:45:29 by kalmheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PGRM	=	push_swap
MAIN	=	main.c
UTIL	=	stackops.c pswap_utils0.c sort_algo.c pswap_utils1.c \
			pswap_utils2.c
SRCS	=	ft_bzero.c ft_digit.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isprint.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
			ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c \
			ft_toupper.c ft_strlcpy.c ft_strlcat.c ft_atoi.c \
			ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_printf0.c ft_printf1.c printers.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS	= ${SRCS:.c=.o}
LBFT	= libft.a
LIBC	= ar rc
LIBR	= ranlib
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

create: compile

all: ${LBFT} compile

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LBFT}: ${OBJS}
	${LIBC} ${LBFT} ${OBJS}
	${LIBR} ${LBFT}

compile: ${LBFT}
	${CC} ${CFLAGS} ${MAIN} ${UTIL} ${LBFT} -o ${PGRM}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${LBFT}
	${RM} ${PGRM}

re: fclean all
