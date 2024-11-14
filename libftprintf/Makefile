# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvives-s <mvives-s@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 09:24:22 by mvives-s          #+#    #+#              #
#    Updated: 2024/10/11 09:24:33 by mvives-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente
SRC = ft_printf.c ft_extfun.c ft_extprint.c

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a

# Archivos objeto
OBJ = $(SRC:.c=.o)

# Regla por defecto: compilar todo
all: $(LIBFT) $(NAME)

# Compilar libft si no existe
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Regla para generar el archivo .a (librería estática)
$(NAME): $(OBJ) $(LIBFT)
	ar rcsv $(NAME) $(OBJ)
	# Añadir libft.a dentro de libftprintf.a
	ar rcsv $(NAME) $(LIBFT_DIR)*.o

# Regla para compilar los archivos .c a .o
%.o: %.c libftprintf.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar los archivos .o
clean:
	rm -f $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR)

# Limpiar los archivos .o y la librería generada
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

# Reconstruir todo
re: fclean all

# Para que make no trate las reglas como archivos
.PHONY: all clean fclean re

