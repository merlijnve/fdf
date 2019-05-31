/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mrelease.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 14:53:41 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/30 16:32:48 by mvan-eng      ########   odam.nl         */
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
		fdf->ang->x = 0;
		fdf->ang->y = 0;
		fdf->ang->z = 90;
	}
	if (key == 20)
	{
		fdf->ang->x = 10;
		fdf->ang->y = 0;
		fdf->ang->z = 45;
	}
	if (key == 30)
	{
		fdf->ang->x = 0;
		fdf->ang->y = 0;
		fdf->ang->z = 0;
	}
	if (key == 40)
	{
		fdf->ang->x = 30;
		fdf->ang->y = 30;
		fdf->ang->z = 30;
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
}

/*
**	Stretching based on button clicked
*/



/*
**	Mouse release handling
*/

int		ft_mrelease(int button, int x, int y, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx->mlx, fdf->mlx->win);
	ft_preset_views_area(x, y, fdf);
	if (button == 2)
		ft_draw_button(x, y, "Made my mvan-eng", fdf);
	ft_calc_points(fdf->mlx, fdf, fdf->ang);
	ft_draw_map(fdf);
	fdf->flag->mpd = 0;
	return (0);
}
