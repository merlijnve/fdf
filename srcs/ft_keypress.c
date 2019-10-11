/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_keypress.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 20:27:04 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/27 12:36:33 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Handles arrow key functionality (Moving the object)
*/

void		ft_arrow_keys(int key, t_fdf *fdf)
{
	t_ang *ang;

	ang = fdf->ang;
	if ((key > 122 && key < 127) || (key == 808 || key == 909))
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
	if (key == 53)
	{
		exit(0);
	}
	ft_preset_views(key, fdf);
	ft_arrow_keys(key, fdf);
	mlx_clear_window(mlx->mlx, mlx->win);
	ft_bzero(fdf->mlx->adr, 1800 * 1300 * 4);
	ft_initialize_rmap(fdf);
	ft_calc_points(mlx, fdf, fdf->ang);
	ft_draw_map(fdf);
	return (0);
}
