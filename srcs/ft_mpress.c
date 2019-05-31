/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mpress.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/29 15:00:11 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/30 11:37:36 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	return (0);
}
