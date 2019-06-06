/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_keypress.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 20:27:04 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/06 20:18:43 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_wasd(int key, t_fdf *fdf)
{
	if (key == 13)
		ft_translate_map(fdf->mlx, fdf->rmap, 0, -10);
	if (key == 1)
		ft_translate_map(fdf->mlx, fdf->rmap, 0, 10);
	if (key == 0)
		ft_translate_map(fdf->mlx, fdf->rmap, -10, 0);
	if (key == 2)
		ft_translate_map(fdf->mlx, fdf->rmap, 10, 0);
}

/*
**	Handles arrow key functionality (Moving the object)
*/

void		ft_arrow_keys(int key, t_fdf *fdf)
{
	t_ang *ang;

	ang = fdf->ang;
	if (((key > 122 && key < 127) || (key == 808 || key == 909)) &&
	fdf->flag->i != 1)
	{
		if (key == 123)
			ang->y -= fdf->flag->r;
		if (key == 124)
			ang->y += fdf->flag->r;
		if (key == 125)
			ang->z -= fdf->flag->r;
		if (key == 126)
			ang->z += fdf->flag->r;
		if (key == 808)
			ang->x -= fdf->flag->r;
		if (key == 909)
			ang->x += fdf->flag->r;
	}
}

/*
**	Collects all keypress handling functions
*/

int			ft_keypress(int key, t_fdf *fdf)
{
	t_grh *mlx;

	mlx = fdf->mlx;
	ft_wasd(key, fdf);
	if (key == 53)
		exit(0);
	ft_preset_views(key, fdf);
	ft_arrow_keys(key, fdf);
	mlx_clear_window(mlx->mlx, mlx->win);
	ft_calc_points(mlx, fdf, fdf->ang);
	ft_draw_map(fdf);
	return (0);
}
