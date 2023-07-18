# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 11:20:10 by melayoub          #+#    #+#              #
#    Updated: 2023/02/24 14:54:33 by melayoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_B = so_long_bonus
HEADER = so_long.h
HEADER_B = so_long_bonus.h
MINILIBX = -lmlx -framework OpenGL -framework AppKit

SRC = mandatory/parsing.c \
	mandatory/parsing1.c \
	mandatory/backtrack.c \
	mandatory/sl_utils.c \
	mandatory/gnl_utils.c \
	mandatory/libft_utils.c \
	mandatory/get_next_line.c \
	mandatory/so_long.c \
	mandatory/maping_setup.c \
	mandatory/maping_making.c \
	mandatory/player_moves.c \
	mandatory/main.c \

B_SRC = bonus/parsing_bonus.c \
	bonus/parsing1_bonus.c \
	bonus/backtrack_bonus.c \
	bonus/sl_utils_bonus.c \
	bonus/gnl_utils_bonus.c \
	bonus/libft_utils_bonus.c \
	bonus/get_next_line_bonus.c \
	bonus/maping_setup_bonus.c \
	bonus/maping_making_bonus.c \
	bonus/animation.c \
	bonus/player_moves_bonus.c \
	bonus/so_long_bonus.c \
	bonus/main_bonus.c \

CC = cc 
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

bonus : $(NAME_B)

$(NAME): $(SRC) $(HEADER)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(MINILIBX)

$(NAME_B): $(B_SRC) $(HEADER_B)
	$(CC) $(FLAGS) $(B_SRC) -o $(NAME_B) $(MINILIBX)

clean:
	$(RM) $(NAME) $(NAME_B)

fclean: clean
	$(RM) $(bonus)

re: fclean all
