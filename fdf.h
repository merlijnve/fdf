/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:02:55 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/04/18 19:43:39 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "minilibx_macos/mlx.h"
#include "math.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct	s_line
{
	int dx;
	int dy;
	int x;
	int y;
	int d;
	int i;
}				t_line;

typedef struct	s_column
{
	int		x;
	int		y;
	int		z;
	void	*next;
}				t_col;

typedef struct	s_row
{
	t_col	*c;
	void	*next;
}				t_row;

t_row	*ft_fdf_catch_input(char *filename);
void	ft_drawline(int x0, int y0, int x1, int y1, void *mlx, void *win);
void	dot_line(int x1, int y1, int x2, int y2, int color, void *mlx, void *win);

#endif
