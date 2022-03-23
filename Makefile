# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 09:41:47 by jperras           #+#    #+#              #
#    Updated: 2022/03/23 16:54:40 by jperras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = pipex.c

NAME = pipex

INCLUDES = -I./includes

OBJS = ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Werror -Wextra 

LIBPF = -L printf -lftprintf

.c.o:
		${CC} ${FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

$NAME: ${OBJS}
	make -C printf
	${CC} ${FLAGS} -o ${NAME} ${LIBPF} ${INCLUDES} ${OBJS}

debug:
	make -C printf
	${CC} ${FLAGS} -o ${NAME} ${LIBPF} ${INCLUDES} ${SRCS}

all: ${NAME}

clean:
	echo ${OBJS}
	make clean -C printf
	rm -rf ${OBJS}


fclean: clean
	make fclean -C printf
	rm -rf ${NAME}

re: fclean all
	make re -C printf

.PHONY: all clean fclean
