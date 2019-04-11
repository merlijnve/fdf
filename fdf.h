/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:02:55 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/04/11 12:42:27 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "minilibx_macos/mlx.h"
#include "math.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

char	**ft_create_imap(char *filename);
void	ft_drawline(int x0, int y0, int x1, int y1, void *mlx, void *win);
void	dot_line(int x1, int y1, int x2, int y2, int color, void *mlx, void *win);

typedef struct	s_line
{
	int dx;
	int dy;
	int x;
	int y;
	int d;
	int i;
}				line;

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				point;

#endif
