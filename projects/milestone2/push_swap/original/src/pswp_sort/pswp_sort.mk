# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pswp_sort.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almounib <almounib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 02:15:59 by marvin            #+#    #+#              #
#    Updated: 2024/05/20 17:07:55 by almounib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PSWP_SORT_DIR		=	pswp_sort

PSWP_SORT_HEADER	=	pswp_sort.h
PSWP_SORT_FILE		=	pswp_sort.c pswp_radix.c

PSWP_SORT			=	$(addprefix $(PSWP_SORT_DIR)/, $(PSWP_SORT_FILE))
PSWP_SORT_HEAD		=	$(addprefix $(PSWP_SORT_DIR)/, $(PSWP_SORT_HEADER))