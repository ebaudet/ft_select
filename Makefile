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
# Directories
DIR_INC	= include
DIR_SRC	= src
DIR_OBJ	= .obj
# Files
NAME	= ft_select
F_SRC	+= main.c
SRC		= $(addprefix $(DIR_SRC)/, $(F_SRC))
OBJ		= $(addprefix $(DIR_OBJ)/, $(subst .c,.o,$(SRC)))
F_INC	+= ft_select.h
INC		= $(addprefix $(DIR_INC)/, $(F_INC))

# Classic Rules:
all: $(DIR_OBJ) $(NAME)
	echo "\033[32mmake: Nothing to be done for 'all'.\033[0m"

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	echo "\033[33m$(CC) -o \033[4m$@\033[0m\033[33m $^ $(CFLAGS)\033[0m"

$(addprefix $(DIR_OBJ)/, %.o): %.c $(INC)
	$(CC) -o $@ -c $< $(CFLAGS) $(LDFLAGS)
	echo "\033[34m$(CC) -o \033[4m$@\033[0m\033[34m -c $< $(CFLAGS) $(LDFLAGS)\033[0m"

$(DIR_OBJ):
	echo "create  folder $(DIR_OBJ)/$(DIR_SRC)"
	/bin/mkdir $(DIR_OBJ);				\
	for DIR in $(DIR_SRC);				\
	do									\
		/bin/mkdir $(DIR_OBJ)/$$DIR;	\
	done								\

clean:
	$(RM) -f $(OBJ)
	echo "\033[31m$(RM) -f \033[0m\033[41m$(OBJ)\033[0m"
	$(RM) -rf $(DIR_OBJ)
	echo "\033[31m$(RM) -rf \033[0m\033[41m$(DIR_OBJ)\033[0m"

fclean: clean
	$(RM) -f $(NAME)
	echo "\033[31m$(RM) -f \033[0m\033[41m$(NAME)\033[0m"

color:
	echo "\033[0mcolor code : 0!\033[0m"
	echo "\033[1mcolor code : 1!\033[0m"
	echo "\033[4mcolor code : 4!\033[0m"
	echo "\033[7mcolor code : 7!\033[0m"

	echo "\033[30mcolor code : 30!\033[0m"
	echo "\033[31mcolor code : 31!\033[0m"
	echo "\033[32mcolor code : 32!\033[0m"
	echo "\033[33mcolor code : 33!\033[0m"
	echo "\033[34mcolor code : 34!\033[0m"
	echo "\033[35mcolor code : 35!\033[0m"
	echo "\033[36mcolor code : 36!\033[0m"

	echo "\033[40mcolor code : 40!\033[0m"
	echo "\033[41mcolor code : 41!\033[0m"
	echo "\033[42mcolor code : 42!\033[0m"
	echo "\033[43mcolor code : 43!\033[0m"
	echo "\033[44mcolor code : 44!\033[0m"
	echo "\033[45mcolor code : 45!\033[0m"
	echo "\033[46mcolor code : 46!\033[0m"
	echo "\033[47mcolor code : 47!\033[0m"

re: fclean all

.SILENT:

.PHONY: all clean fclean re

# Additional Rules:
gdb:
	cc -g $(FLAGS) $(SRC) -o $(NAME)
	gdb $(NAME)
