# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pswp.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 02:15:59 by marvin            #+#    #+#              #
#    Updated: 2024/05/11 21:29:59 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PSWP_DIR		=	pswp

PSWP_HEADER		=	pswp.h
PSWP_FILE		=	pswp.c pswp1.c pswp2.c pswp3.c

PSWP			=	$(addprefix $(PSWP_DIR)/, $(PSWP_FILE))
PSWP_HEAD		=	$(addprefix $(PSWP_DIR)/, $(PSWP_HEADER))