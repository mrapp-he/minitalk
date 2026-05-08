# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 16:37:40 by mrapp-he          #+#    #+#              #
#    Updated: 2025/04/09 19:12:37 by mrapp-he         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC1 = client
EXEC2 = server
SRCS1 = client.c
SRCS2 = server.c
OBJ_DIR = build
OBJS1 = $(SRCS1:%.c=$(OBJ_DIR)/src/%.o)
OBJS2 = $(SRCS2:%.c=$(OBJ_DIR)/src/%.o)
PRINTF = -L lib/ft_printf -lftprintf
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
INCLUDE = -I lib

all: printf $(EXEC1) $(EXEC2)

printf:
	@make -C lib/ft_printf --no-print-directory

$(EXEC1): $(OBJS1)
	@$(CC) $(OBJS1) -o $(EXEC1) $(PRINTF) $(INCLUDE)
	@echo "Client created!"

$(EXEC2): $(OBJS2)
	@$(CC) $(OBJS2) -o $(EXEC2) $(PRINTF) $(INCLUDE)
	@echo "Server created!"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/src
	@echo "Build directory created!"

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
		echo "Build directory deleted!"; \
	else \
		echo "No build directory to delete!"; \
	fi

fclean: clean
	@make fclean -C lib/ft_printf --no-print-directory
	@rm -rf $(EXEC1) $(EXEC2) $(OBJ_DIR)
	@echo "Executables deleted!"

re: fclean
	@echo "Recreating build directory..."
	@echo "Remaking executables..."
	@make --no-print-directory
