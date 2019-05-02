# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/25 19:59:01 by mvan-eng       #+#    #+#                 #
#    Updated: 2019/05/02 15:45:17 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
SRC = main.c libft/libft.a ft_drawline.c ft_fdf_catch_input.c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -I /minilibx_macos/ $(SRC) -L ./minilibx_macos/ -lmlx -framework \
	OpenGL -framework AppKit -o $(NAME) -g

clean:


fclean: clean
	rm -f $(NAME)

re: fclean all
