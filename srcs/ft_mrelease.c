/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mrelease.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 14:53:41 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/11 18:12:03 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Preset angle views based on key given by mrelease,
**	corresponding with the area of the button clicked
*/

void	ft_preset_views(int key, t_fdf *fdf)
{
	if (key == 10)
	{
		fdf->ang->x = 40;
		fdf->ang->y = -24;
		fdf->ang->z = 40;
	}
	if (key == 20)
	{
		fdf->ang->x = 40;
		fdf->ang->y = -204;
		fdf->ang->z = 40;
	}
	if (key == 30)
	{
		fdf->ang->x = 0;
		fdf->ang->y = 0;
		fdf->ang->z = 0;
	}
	if (key == 40)
	{
		fdf->ang->x = 0;
		fdf->ang->y = 0;
		fdf->ang->z = 0;
	}
}

void	ft_preset_views_area(int x, int y, t_fdf *fdf)
{
	if (x > 50 && x < 196 && y > 50 && y < 75)
		ft_preset_views(10, fdf);
	if (x > 50 && x < 196 && y > 100 && y < 125)
		ft_preset_views(20, fdf);
	if (x > 50 && x < 174 && y > 150 && y < 175)
		ft_preset_views(30, fdf);
	if (x > 50 && x < 225 && y > 350 && y < 375)
	{
		fdf->flag->i *= -1;
		ft_preset_views(40, fdf);
	}
	if (x > 50 && x < 255 && y > 400 && y < 425)
	{
		if (fdf->flag->r == 2)
			fdf->flag->r = 8;
		else
			fdf->flag->r = 2;
	}
}

/*
**	Mouse release handling
*/

int		ft_mrelease(int button, int x, int y, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx->mlx, fdf->mlx->win);
	ft_bzero(fdf->mlx->adr, 1800 * 1300 * 4);
	ft_preset_views_area(x, y, fdf);
	if (button == 2)
		ft_draw_button(x, y, "Made my mvan-eng", fdf);
	ft_calc_points(fdf->mlx, fdf, fdf->ang);
	ft_draw_map(fdf);
	fdf->flag->mpd = 0;
	return (0);
}
