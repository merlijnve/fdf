/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_draw_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 20:14:16 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/06 19:47:19 by mvan-eng      ########   odam.nl         */
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

void	ft_save_extrs(t_grh *mlx, t_pnt p)
{
	if (mlx->ef == 0)
	{
		mlx->ymi = p.y;
		mlx->yma = p.y;
		mlx->xmi = p.x;
		mlx->xma = p.x;
	}
	if (p.y > mlx->yma)
		mlx->yma = p.y;
	if (p.y < mlx->ymi)
		mlx->ymi = p.y;
	if (p.x > mlx->xma)
		mlx->xma = p.x;
	if (p.x < mlx->xmi)
		mlx->xmi = p.x;
}

/*
**	Translates the grid to a centered position
*/

void	ft_translate_mid(t_grh *mlx, t_pnt **rmap)
{
	int i;
	int j;
	int xt;
	int yt;

	i = 0;
	j = 0;
	while (i < mlx->rlen)
	{
		while (j < mlx->clen)
		{
			ft_save_extrs(mlx, rmap[i][j]);
			j++;
		}
		j = 0;
		i++;
	}
	xt = mlx->xmi + 1075 - (mlx->xmi + (0.5 * mlx->xma));
	yt = mlx->ymi + 650 - (mlx->ymi + (0.5 * mlx->yma));
	ft_translate_map(mlx, rmap, xt, yt);
}

/*
**	Combines the above functions, all functions can be used separately
*/

void	ft_draw_map(t_fdf *fdf)
{
	int i;

	i = 0;
	ft_translate_mid(fdf->mlx, fdf->rmap);
	ft_connect_dots(fdf->mlx, fdf->rmap);
	ft_show_ui(fdf);
	while (i < 1300)
	{
		mlx_pixel_put(fdf->mlx->mlx, fdf->mlx->win, 300, i, 0xffffff);
		i++;
	}
}
