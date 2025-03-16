# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 14:34:19 by mlaffita          #+#    #+#              #
#    Updated: 2025/03/16 12:46:51 by mlaffita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# nom de l'executable
NAME = so_long

# Source and object diretories
SRCDIR = src
OBJDIR = obj

# Librairies
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
PRINTFDIR = ./ft_printf
PRINTF = $(PRINTFDIR)/libftprintf.a
ifeq ($(shell uname), Darwin)
	MLXDIR = ./minilibx-darwin
	MLX_FRAMEWORK = -framework OpenGL -framework AppKit
else ifeq ($(shell uname), Linux)
	MLXDIR = ./minilibx-linux
	MLX_FRAMEWORK = -lXext -lX11 -lz
endif
MLX = -L $(MLXDIR) -lmlx
MATH_LIB = -lm

# Compiler and flags
CC = gcc
CFLAGS = -g3 -Wall -Wextra -Werror
INCLUDE = -I include -I $(MLXDIR)

RM = rm -f 

# rajouter les fichiers sources ici ////////
vpath %.c \
	$(SRCDIR)\
	$(SRCDIR)/parsing \

# Sources and object files
SRC = main.c parsing.c utils.c # rajouter les fichiers sources ici ////////
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) all -C $(LIBFTDIR)

$(PRINTF):
	$(MAKE) all -C $(PRINTFDIR)

$(MLX):
	$(MAKE) all -C $(MLXDIR)
	
# Compile each .c file to .o		
$(OBJDIR)/%.o: %.c
		@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) $(MLX_FRAMEWORK) $(MATH_LIB) -o $(NAME)

# Rule to clean up object files	
clean:
		$(RM) $(OBJS)
		$(MAKE) clean -C $(LIBFTDIR)
		$(MAKE) clean -C $(PRINTFDIR)
		$(MAKE) clean -C $(MLXDIR)
		@rm -rf $(OBJDIR)

#Rule to clean  up object files and the library
fclean: clean
		$(RM) $(NAME)
		$(MAKE) fclean -C $(LIBFTDIR)
		$(MAKE) fclean -C $(PRINTFDIR)

# Rule to recompile everything
re: fclean all

.PHONY: all clean fclean re