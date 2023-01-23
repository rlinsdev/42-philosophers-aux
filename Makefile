# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlins <rlins@student.42sp.org.br>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 08:04:25 by rlins             #+#    #+#              #
#    Updated: 2023/01/23 08:41:45 by rlins            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# Collors
RESET 	= \033[0m
GREEN 	= \033[0;32m
RED 	= \033[0;31m

# Paths
PATH_SRC 		= ./src/
PATH_MAIN 		= $(PATH_SRC)main/
PATH_OBJS 		= ./objs/

INC_PATH 		= ./include/

# Compilation
CC = gcc

# Compilation flags
CFLAGS = -g
# CFLAGS = -g -Wall -Werror -Wextra

#Chedk Leak memory
LEAK = valgrind --leak-check=full --show-leak-kinds=all \
	--trace-children=yes --track-origins=yes -s

RM			= rm -rf
NO_PRINT	= --no-print-directory
READ_LN		= -l readline

INCLUDE = -I $(INC_PATH)

SRCS =	$(PATH_MAIN)main.c \
		$(PATH_MAIN)race_cond_1.c \

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDE) $(READ_LN)
	@echo "$(GREEN)Build Successful$(RESET)"

$(PATH_OBJS)%.o: $(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)main/
	@$(CC) $(CFLAGS) $(INCLUDE) -I. -c $< -o $@

clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@$(RM) $(PATH_OBJS)
# @make -C clean $(NO_PRINT)
	@echo "$(GREEN)Done!$(RESET)"

fclean: clean
	@echo  "$(RED)Cleaning all...$(RESET)"
	@$(RM) $(NAME)
# @make -C fclean $(NO_PRINT)
	@echo "$(RED)Cleaning binaries...$(RESET)"
	@echo "$(GREEN)Done!$(RESET)"

re: fclean all

bonus: all

rebonus: fclean all

run:
	make re && ./philo

valgrind:
	$(LEAK) ./philo

.PHONY: all run re clean fclean
