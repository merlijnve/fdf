# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/25 19:59:01 by mvan-eng       #+#    #+#                 #
#    Updated: 2019/05/23 14:44:48 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

FILES = main ft_drawline ft_fdf_catch_input ft_calc_points ft_draw_map \
ft_keypress ft_show_ui ft_mmove

LIBS = libft/libft.a

SRC = $(FILES:%=srcs/%.c)

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) $(LIBS) -L ./minilibx_macos/ -lmlx -framework \
	OpenGL -framework AppKit -o $(NAME) -g

clean:


fclean: clean
	rm -f $(NAME)

re: fclean all
