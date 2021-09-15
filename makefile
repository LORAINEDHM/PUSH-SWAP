# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduhamel <lduhamel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 12:20:08 by lduhamel          #+#    #+#              #
#    Updated: 2021/09/15 16:22:44 by lduhamel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -Isrcs -Ilibft


NAME		=	push_swap

SRCS		=	main.c parsing.c list.c \
				sa_sb_ss.c pa_pb.c ra_rb_rr.c rra_rrb_rrr.c \
				actions.c utils.c free.c \

LFT_SRC		=	./libft

LIBFT		=	$(LFT_SRC)/libft.a

OBJ			=	${addprefix srcs/, ${SRCS:.c=.o}}


all:		$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) all -C libft
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o push_swap

clean:
		rm -f $(OBJ)
		$(MAKE) $@ -C libft

fclean:		clean
		rm -f $(NAME)
		$(MAKE) $@ -C libft

re:			fclean all

.PHONY:		all fclean re
