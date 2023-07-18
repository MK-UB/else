# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 11:20:10 by melayoub          #+#    #+#              #
#    Updated: 2023/02/20 12:02:34 by melayoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




NAME = so_long
NAMEB = so_long_bonus
HEADER = so_long.h
HEADERB = so_long_bonus.h
MINILIBX = -lmlx -framework OpenGL -framework AppKit

SRC = mandatory/gnl_utils.c \
	mandatory/get_next_line.c \
	mandatory/libft_utils.c \
	mandatory/parsing.c \
	mandatory/parsing1.c \
	mandatory/player_moves.c\
	mandatory/maping.c\
	mandatory/so_long.c \
	mandatory/main.c\
	mandatory/backtrack.c\

BSRC = bonus/get_next_line_bonus.c \
	bonus/gnl_utils_bonus.c \
	bonus/libft_utils_bonus.c \
	bonus/parsing_bonus.c \
	bonus/parsing1_bonus.c \
	bonus/maping_bonus.c \
	bonus/player_moves_bonus.c\
	bonus/so_long_bonus.c \
	bonus/main_bonus.c \
	bonus/animation.c \
	bonus/backtrack_bonus.c\

CC = cc 
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

bonus : $(NAMEB)

$(NAME): $(SRC) $(HEADER)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(MINILIBX)

$(NAMEB): $(BSRC) $(HEADERB)
	$(CC) $(FLAGS) $(BSRC) -o $(NAMEB) $(MINILIBX)

clean:
	$(RM) $(NAME) $(NAMEB)

fclean: clean
	$(RM) $(bonus)

re: fclean all
