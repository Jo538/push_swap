# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admin <admin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/28 19:41:09 by admin             #+#    #+#              #
#    Updated: 2026/01/28 22:29:22 by admin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -O0 -fsanitize=address -fno-omit-frame-pointer
MAIN_SOURCES = main.c \
	parser/utils.c parser/ft_split.c parser/ft_strjoin.c \
	operations/swap.c operations/push.c operations/rotate.c operations/rrotate.c \
	algo/find_pair1.c algo/find_pair2.c algo/move_up1.c algo/move_up2.c algo/small_sort.c
MAIN_OBJECTS = $(MAIN_SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)
NAME = push_swap

# Default rule
all: $(NAME)

# Compilation of the main executable
$(NAME): $(MAIN_OBJECTS)
	$(CC) $(CFLAGS) $(MAIN_OBJECTS) -o $(NAME)

# Compilation of the .c files into .o files (main + bonus)
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) 

# Phony targets declaration
.PHONY: all clean fclean re bonus

# Compilation of bonus .c files into .o files
bonus: $(BONUS_OBJECTS) $(NAME) 
	ar rcs $(NAME) $(BONUS_OBJECTS)

# Removal of object files
clean:
	rm -f $(MAIN_OBJECTS) $(BONUS_OBJECTS)

# Removal of compiled file
fclean: clean
	rm -f $(NAME)

# Recompile all files
re: fclean all

