# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fhuisman <fhuisman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/04 13:10:38 by fhuisman      #+#    #+#                  #
#    Updated: 2022/12/17 11:43:17 by fhuisman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c conversions.c ft_printf.c hexadecimal.c printunsignedint.c

OBJS = ${SRC:.c=.o}

HEADERS = libft.h ft_printf.h

all: ${NAME}

${NAME}: ${OBJS}
	ar -src ${NAME} ${OBJS}

%.o: %.c ${HEADERS}
	${CC} -c ${FLAGS} -o $@ $<

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re