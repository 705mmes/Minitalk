# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sammeuss <sammeuss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 08:48:44 by sammeuss          #+#    #+#              #
#    Updated: 2023/05/03 13:33:13 by sammeuss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#     ███▄ ▄███▓ ▄▄▄       ██ ▄█▀▓█████   █████▒██▓ ██▓    ▓█████ 
#    ▓██▒▀█▀ ██▒▒████▄     ██▄█▒ ▓█   ▀ ▓██   ▒▓██▒▓██▒    ▓█   ▀ 
#    ▓██    ▓██░▒██  ▀█▄  ▓███▄░ ▒███   ▒████ ░▒██▒▒██░    ▒███   
#    ▒██    ▒██ ░██▄▄▄▄██ ▓██ █▄ ▒▓█  ▄ ░▓█▒  ░░██░▒██░    ▒▓█  ▄ 
#    ▒██▒   ░██▒ ▓█   ▓██▒▒██▒ █▄░▒████▒░▒█░   ░██░░██████▒░▒████▒
#    ░ ▒░   ░  ░ ▒▒   ▓▒█░▒ ▒▒ ▓▒░░ ▒░ ░ ▒ ░   ░▓  ░ ▒░▓  ░░░ ▒░ ░
#    ░  ░      ░  ▒   ▒▒ ░░ ░▒ ▒░ ░ ░  ░ ░      ▒ ░░ ░ ▒  ░ ░ ░  ░
#    ░      ░     ░   ▒   ░ ░░ ░    ░    ░ ░    ▒ ░  ░ ░      ░   
#           ░         ░  ░░  ░      ░  ░        ░      ░  ░   ░  ░
                                                            
NAME = minitalk
PRINT_NAME		= mInItaLk
PRINT_PREFIX	= \033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(PRINT_NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

CSRC = 		client \

SSRC =		server \
			

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3

LIBFT_DIR	= libft/
DIR_SRCS    = src/
DIR_OBJS    = objs/

SSRCS        = $(addprefix $(DIR_SRCS), $(addsuffix .c, $(SSRC)))
SOBJS        = $(addprefix $(DIR_OBJS), $(addsuffix .o, $(SSRC)))
CSRCS        = $(addprefix $(DIR_SRCS), $(addsuffix .c, $(CSRC)))
COBJS        = $(addprefix $(DIR_OBJS), $(addsuffix .o, $(CSRC)))

all: $(NAME)

$(NAME): $(SOBJS) $(COBJS)
		@echo "$(PRINT_PREFIX)\033[0;38;5;226m Compiling \033[0m\n"
		@make -C libft
		@make -C libft bonus
		@$(CC) $(CFLAGS) -o server $(SOBJS) $(LIBFT_DIR)libft.a
		@$(CC) $(CFLAGS) -o client $(COBJS) $(LIBFT_DIR)libft.a
		@echo "$(PRINT_PREFIX)\033[0;38;5;226m Done \033[0m\n"

$(DIR_OBJS)%.o :	$(DIR_SRCS)%.c $(OBJF)
				@mkdir -p $(DIR_OBJS)
				@$(CC) $(CFLAGS) -c $< -o $@

clean:
		@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
		@rm -f $(OBJS)
		@make -C libft/ clean
		@rm -r $(DIR_OBJS)
		@echo "$(PRINT_PREFIX)\033[0;38;5;226m Done \033[0m\n"

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test