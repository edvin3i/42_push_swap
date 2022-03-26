# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 08:25:42 by gbreana           #+#    #+#              #
#    Updated: 2022/03/24 11:40:47 by gbreana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

INCL			= ./include/push_swap.h

LIB			=	-L ./libft -lft
LIBFT		=	libft.a

MSRC		=	sources/mandatory/main.c sources/mandatory/parser.c sources/mandatory/validation.c\
				sources/mandatory/init.c
BSRC		=	sources/checker/*


MOBJS		=	$(patsubst %.c,%.o,$(MSRC))
BOBJS		=	$(patsubst %.c,%.o,$(BSRC))

MDEPS		=	$(patsubst %.c,%.d,$(MSRC))
BDEPS		=	$(patsubst %.c,%.d,$(BSRC))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -MD
RM			=	rm -rf

override		OBJS_ALL ?= $(MOBJS)
override		DEP_ALL ?= $(DEPS)

%.o:			%.c Makefile libft/libft.a
				$(CC) $(CFLAGS) -I $(INCL) -c $< -o ${<:.c=.o}


all:			$(LIBFT) $(NAME)

$(LIBFT):
				@make -C libft


$(NAME):		$(LIBFT) $(MOBJS)
				@$(CC) $(MOBJS) $(LIB) -o $@

bonus:			$(LIBFT) $(BOBJS)
				@$(CC) $(BOBJS) $(LIB) -o $@

clean:
				@make clean -C libft
				$(RM) $(MOBJS) $(MDEPS) $(BOBJS) $(BDEPS)

fclean:			clean
				@make fclean -C libft
				$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re bonus
