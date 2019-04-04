# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/25 19:59:01 by mvan-eng       #+#    #+#                 #
#    Updated: 2019/04/04 20:19:01 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRC = main.c libft/libft.a ft_drawline.c

all: $(NAME)

$(NAME):
	gcc -I /minilibx_macos/ $(SRC) -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

clean:


fclean: clean
	rm -f $(NAME)

re: fclean all