/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mmove.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 14:20:10 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/05 18:35:58 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Handle mousemovement, changes angle based on movement
*/

int	ft_mmove(int x, int y, t_fdf *fdf)
{
	t_pnt p0;
	t_pnt p1;

	p0.x = x;
	p0.y = y;
	//printf("x: %d, y: %d\n", x, y);
	if (fdf->flag->mpd == 1)
	{
		p1.x = fdf->flag->ix;
		p1.y = fdf->flag->iy;
		ft_drawline(p0, p1, fdf->mlx);
	}
	return (0);
}
