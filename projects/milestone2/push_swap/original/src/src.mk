# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almounib <almounib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 18:55:59 by marvin            #+#    #+#              #
#    Updated: 2024/05/20 17:05:51 by almounib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include $(CURDIR)/src/pswp/pswp.mk
include $(CURDIR)/src/pswp_list/pswp_list.mk
include $(CURDIR)/src/pswp_sort/pswp_sort.mk

SRC_DIR		=	$(CURDIR)/src

LIB_HEADER	=	$(addprefix $(SRC_DIR)/, push_swap.h)
SRC_HEADER	=	types.h all.h
SRC_FILES	=	push_swap.c

DIR			+= $(PSWP_DIR)
DIR			+= $(PSWP_LIST_DIR)
DIR			+= $(PSWP_SORT_DIR)

SRC_HEADER	+= $(PSWP_HEAD)
SRC_HEADER	+= $(PSWP_LIST_HEAD)
SRC_HEADER	+= $(PSWP_SORT_HEAD)

SRC_FILES	+= $(PSWP)
SRC_FILES	+= $(PSWP_LIST)
SRC_FILES	+= $(PSWP_SORT)

HEADERS		=	$(addprefix $(SRC_DIR)/, $(SRC_HEADER))
SRC			=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
FOLDERS		=	$(addprefix $(SRC_DIR)/, $(DIR))
FOLDERS		+=	$(SRC_DIR)
