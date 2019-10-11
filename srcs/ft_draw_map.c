/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_draw_map.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 20:14:16 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/27 16:23:49 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Draw lines between all points in the grid
*/

void	ft_connect_dots(t_fdf *fdf, t_pnt **map)
{
	int		i;
	int		j;
	t_grh	*mlx;

	mlx = fdf->mlx;
	i = 0;
	j = 0;
	while (i < mlx->rlen)
	{
		while (j < mlx->clen)
		{
			if (j < mlx->clen - 1)
				ft_drawline(map[i][j], map[i][j + 1], fdf);
			if (i < mlx->rlen - 1)
				ft_drawline(map[i][j], map[i + 1][j], fdf);
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

void	ft_translate_mid(t_fdf *fdf, t_pnt **rmap)
{
	int		i;
	int		j;
	int		xt;
	int		yt;
	t_grh	*mlx;

	mlx = fdf->mlx;
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
	int x;
	int	j;

	j = 0;
	x = 300;
	i = 0;
	ft_translate_mid(fdf, fdf->rmap);
	ft_connect_dots(fdf, fdf->rmap);
	while (i < 1300)
	{
		ft_imgpxlput(fdf, 0xffffff, 300, i);
		i++;
	}
	ft_show_ui(fdf);
	mlx_put_image_to_window(fdf->mlx->mlx, fdf->mlx->win, fdf->mlx->img, 0, 0);
	ft_show_txt(fdf);
	while (j < fdf->mlx->rlen)
	{
		ft_memdel((void **)&fdf->rmap[j]);
		j++;
	}
	free(fdf->rmap);
}
