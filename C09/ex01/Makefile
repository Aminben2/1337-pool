# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/10 21:52:16 by mbenomar          #+#    #+#              #
#    Updated: 2024/08/15 18:07:13 by mbenomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./srcs/ft_putchar.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c ./srcs/ft_putstr.c ./srcs/ft_putchar.c
LIBC = libft.a
RM = rm -f
AR = ar rc
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = ./includes

all : ${LIBC}

${LIBC} : ${OBJS}
	${AR} ${LIBC} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ -I${INC}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${LIBC}

re : fclean all
