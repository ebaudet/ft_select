#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 13:31:30 by ebaudet           #+#    #+#              #
#    Updated: 2013/12/31 13:46:38 by apieropa         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# General options
CC		= gcc
RM		= /bin/rm
# Flags
CFLAGS	= -Wall -Wextra -Werror -pedantic
LDFLAGS	= -I $(DIR_INC)
LIB_FT	= -I libft/includes -L libft/ -lft
LIB_TERMCAT = -L /usr/lib -ltermcap
# Directories
DIR_INC	= include
DIR_SRC	= src
DIR_OBJ	= .obj
# Files
NAME	= ft_select
F_SRC	+= main.c
F_SRC	+= eb_list.c
F_SRC	+= eb_tools.c
F_SRC	+= eb_print.c
SRC		= $(addprefix $(DIR_SRC)/, $(F_SRC))
OBJ		= $(addprefix $(DIR_OBJ)/, $(subst .c,.o,$(SRC)))
F_INC	+= ft_select.h
INC		= $(addprefix $(DIR_INC)/, $(F_INC))

# Classic Rules:
all: $(DIR_OBJ) $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31mCompilation de la libft...\033[0m"
	@make -C libft
	@$(CC) -o $@ $^ $(CFLAGS) $(LIB_FT) $(LIB_TERMCAT)
	@echo "\033[33m$(CC) -o \033[4m$@\033[0m\033[33m $^ $(CFLAGS) $(LIB_FT) $(LIB_TERMCAT)\033[0m"

$(addprefix $(DIR_OBJ)/, %.o): %.c $(INC)
	@$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)
	@echo "\033[34m$(CC) -o \033[4m$@\033[0m\033[34m -c $< $(CFLAGS) $(LDFLAGS)\033[0m"

$(DIR_OBJ):
	@echo "create  folder $(DIR_OBJ)/$(DIR_SRC)"
	@/bin/mkdir $(DIR_OBJ)
	@/bin/mkdir $(DIR_OBJ)/$(DIR_SRC)

clean:
	@$(RM) -f $(OBJ)
	@echo "\033[31m$(RM) -f \033[0m\033[41m$(OBJ)\033[0m"
	@$(RM) -rf $(DIR_OBJ)
	@echo "\033[31m$(RM) -rf \033[0m\033[41m$(DIR_OBJ)\033[0m"

fclean: clean
	@$(RM) -f $(NAME)
	@echo "\033[31m$(RM) -f \033[0m\033[41m$(NAME)\033[0m"

color:
	@echo "\033[0mcolor code : 0!\033[0m"
	@echo "\033[1mcolor code : 1!\033[0m"
	@echo "\033[4mcolor code : 4!\033[0m"
	@echo "\033[7mcolor code : 7!\033[0m"

	@echo "\033[30mcolor code : 30!\033[0m"
	@echo "\033[31mcolor code : 31!\033[0m"
	@echo "\033[32mcolor code : 32!\033[0m"
	@echo "\033[33mcolor code : 33!\033[0m"
	@echo "\033[34mcolor code : 34!\033[0m"
	@echo "\033[35mcolor code : 35!\033[0m"
	@echo "\033[36mcolor code : 36!\033[0m"

	@echo "\033[40mcolor code : 40!\033[0m"
	@echo "\033[41mcolor code : 41!\033[0m"
	@echo "\033[42mcolor code : 42!\033[0m"
	@echo "\033[43mcolor code : 43!\033[0m"
	@echo "\033[44mcolor code : 44!\033[0m"
	@echo "\033[45mcolor code : 45!\033[0m"
	@echo "\033[46mcolor code : 46!\033[0m"
	@echo "\033[47mcolor code : 47!\033[0m"

re: fclean all

.PHONY: all clean fclean re

# Additional Rules:
gdb:
	cc -g $(FLAGS) $(SRC) -o $(NAME) $(LDFLAGS) $(LIB_FT) $(LIB_TERMCAT)
	gdb $(NAME)
