# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 09:41:47 by jperras           #+#    #+#              #
#    Updated: 2022/03/25 14:07:11 by jperras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = pipex.c ft_split.c ft_strjoin.c ft_strncmp.c

NAME = pipex

INCLUDES = -I./includes

OBJS = ${SRCS:.c=.o}

CC = gcc

FLAGS = -Wall -Werror -Wextra 

LIBPF = -L printf -lftprintf

.c.o:
		${CC} ${FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C printf
	${CC} ${FLAGS} -o ${NAME} ${LIBPF} ${INCLUDES} ${OBJS}

debug:
	make -C printf
	${CC} ${FLAGS} -g -o ${NAME} ${LIBPF} ${INCLUDES} ${SRCS}
	lldb ./pipex

all: ${NAME}

clean:
	make clean -C printf
	rm -rf ${OBJS}


fclean: clean
	make fclean -C printf
	rm -rf ${NAME}

re: fclean all
	make re -C printf

.PHONY: all clean fclean
