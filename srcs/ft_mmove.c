/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mmove.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 14:20:10 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/23 15:10:35 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_mmove(int x, int y, t_fdf *fdf)
{
	int	dx;
	
	(void)y;
	if (fdf->flag->mpd == 1)
	{
		mlx_pixel_put(fdf->mlx->mlx, fdf->mlx->win, x, y, 0xffffff);
		dx = fdf->flag->ix - x;
		if (dx > 1 || dx < -1)
		{
			fdf->flag->ix = x;
			if (dx > 1)
				fdf->ang->x += 3;
			if (dx < -1)
				fdf->ang->x -= 3;
			mlx_clear_window(fdf->mlx->mlx, fdf->mlx->win);
			ft_draw_map(fdf);
		}
		ft_putnbr(fdf->flag->mpd);
	}
	return (0);
}
