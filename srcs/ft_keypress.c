/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_keypress.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 20:27:04 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/29 22:01:17 by mvan-eng      ########   odam.nl         */
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

static void	ft_arrow_keys(int key, t_fdf *fdf)
{
	t_ang *ang;

	ang = fdf->ang;
	if (key == 123 || key == 124 || key == 125 || key == 126)
	{
		if (key == 123)
			ang->y -= 3;
		if (key == 124)
			ang->y += 3;
		if (key == 125)
			ang->z -= 3;
		if (key == 126)
			ang->z += 3;
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