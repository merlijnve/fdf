/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_draw_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 20:14:16 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/29 22:09:05 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Draw lines between all points in the grid
*/

void	ft_connect_dots(t_grh *mlx, t_pnt **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < mlx->rlen)
	{
		while (j < mlx->clen)
		{
			if (j < mlx->clen - 1)
				ft_drawline(map[i][j], map[i][j + 1], mlx);
			if (i < mlx->rlen - 1)
				ft_drawline(map[i][j], map[i + 1][j], mlx);
			j++;
		}
		j = 0;
		i++;
	}
}

/*
**	Translate map with a given X and Y offset
*/

void	ft_translate_map(t_grh *mlx, t_pnt **map, int xt, int yt)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < mlx->rlen)
	{
		while (j < mlx->clen)
		{
			map[i][j].x += xt;
			map[i][j].y += yt;
			j++;
		}
		j = 0;
		i++;
	}
}

/*
**	Translates the grid to a centered position
*/

void	ft_translate_mid(t_grh *mlx, t_pnt **rmap)
{
	int	ch;
	int	rh;
	int xt;
	int yt;

	ch = trunc(0.5 * mlx->clen);
	rh = trunc(0.5 * mlx->rlen);
	printf("rh: %d, ch: %d\n", rh, ch);
	xt = rmap[rh][ch - 1].x + (0.5 * (rmap[rh][ch].x - rmap[rh][ch - 1].x));
	yt = rmap[rh][ch - 1].y + (0.5 * (rmap[rh][ch].y - rmap[rh][ch - 1].y));
	xt = 1075 - xt;
	yt = 650 - yt + mlx->scale;
	ft_translate_map(mlx, rmap, xt, yt);
}

/*
**	Combines the above functions, all functions can be used separately
*/

void	ft_draw_map(t_fdf *fdf)
{
	ft_translate_mid(fdf->mlx, fdf->rmap);
	ft_connect_dots(fdf->mlx, fdf->rmap);
	ft_show_ui(fdf);
}