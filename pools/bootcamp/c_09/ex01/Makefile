# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almounib <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 12:02:17 by almounib          #+#    #+#              #
#    Updated: 2023/09/27 16:34:05 by almounib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
PRE	= ./srcs/
FILE	= ${addprefix ${PRE}, ${SRCS}}
OBJECTS	= ${FILE:.c=.o}
HEAD	= ./includes/
AR	= ar rc
RM	= rm -f
LIB	= ranlib
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

all	: ${NAME}

.c.o	: 
	${CC} ${CFLAGS} -c $< -I ${HEAD} -o ${<:.c=.o}

${NAME}	: ${OBJECTS} 
	${AR} ${NAME} ${OBJECTS}
	${LIB} ${NAME}

clean	: 
	${RM} ${OBJECTS}

fclean	: clean 
	${RM} ${NAME}

re	: fclean all

.PHONY	: all clean fclean re
