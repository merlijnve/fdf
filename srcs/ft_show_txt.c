/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_show_txt.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/11 19:15:09 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/11 19:52:13 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_show_txt(t_fdf *fdf)
{
	t_grh	*mlx;
	int		x;
	int		y;

	x = 50;
	y = 50;
	mlx = fdf->mlx;
	mlx_string_put(mlx->mlx, mlx->win, x + 72, y + 780, 0xffffff, "Size");
	mlx_string_put(mlx->mlx, mlx->win, x + 72, y + 680, 0xffffff, "Height");
	mlx_string_put(mlx->mlx, mlx->win, x + 52, y + 553, 0xffffff, "Z");
	mlx_string_put(mlx->mlx, mlx->win, x + 52, y + 503, 0xffffff, "Y");
	mlx_string_put(mlx->mlx, mlx->win, x + 52, y + 453, 0xffffff, "X");
	mlx_string_put(mlx->mlx, mlx->win, x + 10, y + 553, 0, "<       >");
	mlx_string_put(mlx->mlx, mlx->win, x + 10, y + 503, 0, "<       >");
	mlx_string_put(mlx->mlx, mlx->win, x + 10, y + 453, 0, "<       >");
	mlx_string_put(mlx->mlx, mlx->win, x + 10, y, 0, "View 1");
	mlx_string_put(mlx->mlx, mlx->win, x + 10, y + 50, 0, "View 1 - Reverse");
	mlx_string_put(mlx->mlx, mlx->win, x + 10, y + 100, 0, "Top view");
	mlx_string_put(mlx->mlx, mlx->win, x + 10, y + 300, 0, "Isometric view");
	mlx_string_put(mlx->mlx, mlx->win, x + 10, y + 350, 0, "Rotate speed x 4");
	mlx_string_put(mlx->mlx, mlx->win, x + 15, y + 650, 0, "/\\");
	mlx_string_put(mlx->mlx, mlx->win, x + 15, y + 690, 0, "\\/");
	mlx_string_put(mlx->mlx, mlx->win, x + 15, y + 750, 0, "/\\");
	mlx_string_put(mlx->mlx, mlx->win, x + 15, y + 790, 0, "\\/");
}
