# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    pswp_list.mk                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almounib <almounib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 02:15:59 by marvin            #+#    #+#              #
#    Updated: 2024/05/20 17:39:08 by almounib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PSWP_LIST_DIR		=	pswp_list

PSWP_LIST_HEADER	=	pswp_list.h
PSWP_LIST_FILE		=	pswp_list.c pswp_list_add.c pswp_list_remove.c

PSWP_LIST			=	$(addprefix $(PSWP_LIST_DIR)/, $(PSWP_LIST_FILE))
PSWP_LIST_HEAD		=	$(addprefix $(PSWP_LIST_DIR)/, $(PSWP_LIST_HEADER))