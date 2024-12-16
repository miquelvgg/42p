# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvives-s <mvives-s@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 09:24:22 by mvives-s          #+#    #+#              #
#    Updated: 2024/09/18 09:24:33 by mvives-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Archivos fuente
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
      ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
      ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
      ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
      ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
      ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
            ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
            ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

# Archivos objeto
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

# Regla por defecto: compilar todo
all: $(NAME)

# Regla para generar el archivo .a (librería estática)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

# Regla para compilar los archivos .c a .o  $@ = objetivo de la regla
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar los archivos .o
clean:
	rm -f $(OBJ) $(OBJ_BONUS)

# Limpiar los archivos .o y la librería generada
fclean: clean
	rm -f $(NAME)

# Reconstruir todo
re: fclean all

# Para que make no trate las reglas como archivos
.PHONY: all clean fclean re bonus
