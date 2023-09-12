# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fhuisman <fhuisman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/25 12:25:31 by fhuisman      #+#    #+#                  #
#    Updated: 2023/02/02 15:25:58 by fhuisman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CHECKER = checker

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = push_swap_utils1.c push_swap_utils2.c push_swap.c sort_big.c sort_small.c validate_args.c validate_args1.c moves.c swaps.c

BONUSSRC = validate_args.c validate_args1.c bonus1.c push_swap_utils1.c swaps.c bonus2.c

OBJS = ${SRC:.c=.o}

BONUSOBJS = ${BONUSSRC:.c=.o}

HEADERS = push_swap.h bonus.h

LIBFT = libft/libft.a

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C libft
	${CC} ${FLAGS} -o ${NAME} ${OBJS} ${LIBFT}

%.o: %.c ${HEADERS}
	${CC} -c ${FLAGS} -o $@ $<

bonus: ${CHECKER}

${CHECKER}: ${BONUSOBJS}
	${CC} ${FLAGS} -o ${CHECKER} ${BONUSOBJS}

clean:
	rm -f ${OBJS} ${BONUSOBJS}
	${MAKE} clean -C libft

fclean: clean
	rm -f ${NAME} ${CHECKER}
	${MAKE} fclean -C libft

re: fclean all
	${MAKE} fclean all -C libft

.PHONY: all clean fclean re bonus