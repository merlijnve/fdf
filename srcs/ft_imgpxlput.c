/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_imgpxlput.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 18:59:22 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/11 18:25:38 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_imgpxlput(t_fdf *fdf, int color, int x, int y)
{
	char	*adr;

	adr = fdf->mlx->adr;
	ft_memcpy(&adr[(4 * x + (4 * 1800 * y))], &color, 3);
}
