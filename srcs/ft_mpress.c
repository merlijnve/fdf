/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mpress.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 15:00:11 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/28 11:10:04 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rot_button(int x, int y, t_fdf *fdf)
{
	if (x > 50 && x < 82 && y > 500 && y < 532)
		ft_arrow_keys(808, fdf);
	if (x > 132 && x < 172 && y > 500 && y < 532)
		ft_arrow_keys(909, fdf);
	if (x > 50 && x < 82 && y > 550 && y < 582)
		ft_arrow_keys(123, fdf);
	if (x > 132 && x < 172 && y > 550 && y < 582)
		ft_arrow_keys(124, fdf);
	if (x > 50 && x < 82 && y > 600 && y < 632)
		ft_arrow_keys(125, fdf);
	if (x > 132 && x < 172 && y > 600 && y < 632)
		ft_arrow_keys(126, fdf);
	if (x > 50 && x < 95 && y > 700 && y < 730 && fdf->mlx->height < 35)
		fdf->mlx->height += 2;
	if (x > 50 && x < 95 && y > 740 && y < 770 && fdf->mlx->height > -35)
		fdf->mlx->height -= 2;
	if (x > 50 && x < 95 && y > 800 && y < 830)
		fdf->mlx->scale += 2;
	if (x > 50 && x < 95 && y > 840 && y < 870 && fdf->mlx->scale > 1)
		fdf->mlx->scale -= 2;
}

/*
**	Handling mousepress, sets the coordinates clicked
*/

int		ft_mpress(int button, int x, int y, t_fdf *fdf)
{
	if (button != 1)
		return (0);
	fdf->flag->mpd = 1;
	fdf->flag->ix = x;
	fdf->flag->iy = y;
	ft_rot_button(x, y, fdf);
	return (0);
}
