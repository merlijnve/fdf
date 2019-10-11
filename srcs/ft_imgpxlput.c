/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_imgpxlput.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 18:59:22 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/27 14:36:06 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Pixelput for image use, copies a given color to the correct location
**	in memory set by mlx_get_data_addr
*/

void	ft_imgpxlput(t_fdf *fdf, int color, int x, int y)
{
	char	*adr;

	adr = fdf->mlx->adr;
	ft_memcpy(&adr[(4 * x + (4 * 1800 * y))], &color, 3);
}
