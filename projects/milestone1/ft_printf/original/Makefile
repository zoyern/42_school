# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almounib <almounib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 16:43:34 by zoyern            #+#    #+#              #
#    Updated: 2024/01/16 12:40:29 by almounib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES	=	ft_printf.c\
			ft_printf_operator.c\
			ft_putnchar_fd.c\
			ft_putnstr_fd.c\
			ft_putnptr_fd.c\
			ft_putnnbr_base_fd.c\
			ft_uputnnbr_base_fd.c\
			ft_neg_to_pos.c\
			ft_strncmp.c\
			ft_get_base.c\
			ft_itoa_base.c\
			ft_uitoa_base.c\
			ft_nbrlen.c\
			ft_nbrlen_base.c\
			ft_unbrlen_base.c\

OBJECTS	=	${FILES:.c=.o}

AR		=	ar rcs
RM	 	=	rm -f
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

all		:	${NAME}

.c.o	:
			${CC} ${CFLAGS} -c -I ./ $< -o ${<:.c=.o}

${NAME}	:	${OBJECTS}
			${AR} ${NAME} ${OBJECTS}

clean	:
			${RM} ${OBJECTS} ${BONUSOBJ}

fclean	:		clean
			${RM} ${NAME}

re		:	fclean all

.PHONY	:	all bonus clean fclean re