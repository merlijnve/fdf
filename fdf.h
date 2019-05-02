/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:02:55 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/02 19:49:53 by mvan-eng      ########   odam.nl         */
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
	int 	dx;
	int 	dy;
	int		x;
	int 	y;
	int 	d;
	int 	i;
}				t_line;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
}				t_pnt;

typedef struct	s_grh
{
	void	*mlx;
	void 	*win;
	int		llen;
	int		rlen;
	int		clen;
}				t_grh;

void	ft_drawline(t_pnt *p0, t_pnt *p1, t_grh *mlx);
void	ft_show_map(t_grh *mlx, t_pnt **map);
t_pnt	**ft_fdf_catch_input(char *filename, t_grh *mlx);

#endif
