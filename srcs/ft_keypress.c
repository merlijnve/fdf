/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_keypress.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 20:27:04 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/23 14:57:17 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_wasd(int key, t_fdf *fdf)
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

void	ft_preset_views(int key, t_fdf *fdf)
{
	if (key == 1)
	{
		fdf->ang->x = 0;
		fdf->ang->y = 0;
		fdf->ang->z = 90;
	}
	if (key == 2)
	{
		fdf->ang->x = 10;
		fdf->ang->y = 0;
		fdf->ang->z = 45;
	}
	if (key == 3)
	{
		fdf->ang->x = 0;
		fdf->ang->y = 30;
		fdf->ang->z = 30;
	}
	if (key == 4)
	{
		fdf->ang->x = 0;
		fdf->ang->y = 0;
		fdf->ang->z = 0;
	}
}

void	ft_arrow_keys(int key, t_fdf *fdf)
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

int		ft_mpress(int button, int x, int y, t_fdf *fdf)
{
	if (button != 1)
		return (0);
	fdf->flag->mpd = 1;
	fdf->flag->ix = x;
	fdf->flag->iy = y;
	ft_putnbr(fdf->flag->mpd);
	return (0);
}

int		ft_keypress(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(0);
	ft_preset_views(key, fdf);
	ft_arrow_keys(key, fdf);
	ft_wasd(key, fdf);
	mlx_clear_window(fdf->mlx->mlx, fdf->mlx->win);
	ft_calc_points(fdf->mlx, fdf, fdf->ang);
	ft_draw_map(fdf);
	return (0);
}
