# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igerasim <igerasim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/13 07:33:52 by igerasim          #+#    #+#              #
#    Updated: 2025/12/01 11:53:05 by igerasim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c\
		ft_dispatch.c\
		ft_print_alpha.c\
		ft_print_nbr.c\
		ft_print_hex.c\

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "ft_printf successfully compiled!"

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)
	@echo "Cleaned objects"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "Cleaned library"

re: fclean all

.PHONY: all clean fclean re