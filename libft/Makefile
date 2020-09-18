# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 17:57:50 by pcoureau          #+#    #+#              #
#    Updated: 2020/02/25 17:51:28 by pcoureau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a
SRCS    =	ft_atoi.c ft_isprint.c ft_putchar_fd.c ft_strjoin.c ft_substr.c \
ft_bzero.c ft_memccpy.c ft_putendl_fd.c ft_strlcat.c ft_tolower.c ft_strrchr.c \
ft_calloc.c ft_memchr.c ft_putnbr_fd.c  ft_strlcpy.c ft_toupper.c \
ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlen.c ft_isalpha.c ft_memcpy.c \
ft_split.c ft_strncmp.c ft_isascii.c ft_memmove.c ft_strchr.c ft_strnstr.c \
ft_isdigit.c ft_memset.c ft_strdup.c ft_strtrim.c ft_itoa.c ft_strmapi.c \
get_next_line.c \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

SRCDIR    = ./
CC        = gcc
FLAGS    = -Wall -Wextra -Werror
OBJ        = $(addprefix $(SRCDIR), $(SRCS:.c=.o))

$(SRCDIR)%.o:    $(SRCDIR)%.c
	$(CC) $(FLAGS) -o $@ -c $<

$(NAME):         $(OBJ)
	ar rc $(NAME) $(OBJ)

all:             $(NAME)

clean:
	rm -f $(OBJ)

fclean:         clean
	rm -f $(NAME)

re:             fclean all

.PHONY:            all clean fclean re
