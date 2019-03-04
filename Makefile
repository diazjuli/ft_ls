# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/15 19:22:08 by jdiaz             #+#    #+#              #
#    Updated: 2018/11/13 17:37:06 by jdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

### PATH ###
SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

FLAGS	= -Wall -Werror -Wextra
INC		= -I ./includes/ -I ./$(LIBFT_PATH)includes/

SRC		= srcs/main.c srcs/print.c srcs/list.c srcs/tools.c srcs/recursive.c

OBJ 	= main.o print.o list.o tools.o recursive.o

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(INC) -c $(SRC)
	@gcc -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft
	@echo "Compiled $(NAME)"

clean:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(OBJ)
	@echo "Cleaned $(OBJS_LIST)"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "Cleaned $(NAME)"

re: fclean all

.PHONY: all, clean, fclean, re
