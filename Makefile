# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/25 19:59:01 by mvan-eng       #+#    #+#                 #
#    Updated: 2019/06/28 11:32:07 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror

FILES = main ft_drawline ft_fdf_catch_input ft_calc_points ft_draw_map \
ft_keypress ft_show_ui ft_mrelease ft_mpress ft_imgpxlput ft_show_txt

LIBS = libft/libft.a

SRC = $(FILES:%=srcs/%.c)

all: $(NAME)

$(NAME):
	cd libft && make
	gcc $(FLAGS) $(SRC) $(LIBS) -L ./minilibx_macos/ -lmlx -framework \
	OpenGL -framework AppKit -o $(NAME)

clean:
	cd libft && make clean

fclean: clean
	rm -f $(NAME)
	cd libft && make fclean

re: fclean all
