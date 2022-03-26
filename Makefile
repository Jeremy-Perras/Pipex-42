# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 09:41:47 by jperras           #+#    #+#              #
#    Updated: 2022/03/26 13:11:13 by jperras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRCS = pipex.c ft_split.c ft_strjoin.c ft_strncmp.c pipex_utils.c

SRCSB = xpipex.c ft_split.c ft_strjoin.c ft_strncmp.c xpipex_utils.c

NAME = pipex

INCLUDES = -I./includes

OBJS = ${SRCS:.c=.o}

OBJSB = ${SRCSB:.c=.o}

CC = gcc

FLAGS = -Wall -Werror -Wextra 

LIBPF = -L printf -lftprintf

.c.o:
		${CC} ${FLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C printf
	${CC} ${FLAGS} -o ${NAME} ${LIBPF} ${INCLUDES} ${OBJS}

bonus: ${OBJSB}
	make -C printf
	${CC} ${FLAGS} -o ${NAME} ${LIBPF} ${INCLUDES} ${OBJSB}

debug:
	make -C printf
	${CC} ${FLAGS} -g -o ${NAME} ${LIBPF} ${INCLUDES} ${SRCSB}
	lldb ./pipex

all: ${NAME}

clean:
	make clean -C printf
	rm -rf ${OBJS} ${OBJSB}


fclean: clean
	make fclean -C printf
	rm -rf ${NAME}

re: fclean all
	make re -C printf

.PHONY: all clean fclean
