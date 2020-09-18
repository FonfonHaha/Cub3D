# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 19:31:45 by pcoureau          #+#    #+#              #
#    Updated: 2020/02/27 20:18:39 by pcoureau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Cub3D
SRC		=   main.c \
            parse.c \
            parse_map.c \
            utils.c \
            print.c \
            utilsii.c 

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
FT		= ./libft/
FT_MLX 	= ./minilibx-linux/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/libft
FT_LNK	= -L ./libft -l ft -l pthread
MLX_LNK	= -I ./minilibx-linux -L ./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd 
SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/
all: obj $(FT_LIB) $(FT_MLX) $(NAME)
obj:
	mkdir -p $(OBJDIR)
$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<
$(FT_LIB):
	make -C $(FT_MLX)
	make -C $(FT)
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_LNK) $(MLX_LNK) -lm -o $(NAME)
clean:
	rm -f $(OBJ)
	make -C $(FT) clean
	make -C $(FT_MLX) clean
fclean: clean
	rm -f $(NAME)
	make -C $(FT) fclean
	make -C $(FT_MLX) clean
re: fclean all
