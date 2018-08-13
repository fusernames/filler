# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 06:10:43 by alcaroff          #+#    #+#              #
#    Updated: 2018/08/13 09:11:54 by alcaroff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	alcaroff.filler
FLAGS			=	-Wall -Werror -Wextra
LIBFT			= 	libft/libft.a
LIBFT_INCLUDES	=	libft/includes
INCLUDES		= 	includes
SRC				=	\
	filler.c \
	ft_can_place.c \
	ft_parser.c \
	ft_place.c \
	ft_resolve.c \
	ft_score.c
OBJ				=	$(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -I $(INCLUDES) -I $(LIBFT_INCLUDES)

clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C libft

re: fclean all
