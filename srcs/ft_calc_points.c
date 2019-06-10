/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calc_points.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 13:02:56 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/10 15:06:17 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Adds isometric calculation to projection
*/

static void	ft_calc_iso(t_pnt *r)
{
	int x;
	int y;

	x = r->x;
	y = r->y;
	r->x = (x - y) * cos(0.523599);
	r->y = -r->z + (x + y) * sin(0.523599);
}

/*
**	Calculate projection
*/

static void	ft_calc_math(t_pnt *p, t_pnt *r, t_ang *ang, t_fdf *fdf)
{
	int		x;
	int		y;
	int		z;
	t_fl	*flag;
	double	d;

	d = M_PI / 180;
	flag = fdf->flag;
	z = fdf->mlx->height * p->z;
	x = fdf->mlx->scale * p->x;
	r->z = z * cos(ang->y * d) - x * sin(ang->y * d);
	r->x = z * sin(ang->y * d) + x * cos(ang->y * d);
	y = fdf->mlx->scale * p->y;
	r->y = y * cos(ang->x * d) - r->z * sin(ang->x * d);
	r->z = y * sin(ang->x * d) + r->z * cos(ang->x * d);
	x = r->x;
	r->x = x * cos(ang->z * d) - r->y * sin(ang->z * d);
	r->y = x * sin(ang->z * d) + r->y * cos(ang->z * d);
	if (flag->i == 1)
		ft_calc_iso(r);
}

/*
**	Loop through all points in the grid and calculate new position with angles
*/

void		ft_calc_points(t_grh *mlx, t_fdf *fdf, t_ang *ang)
{
	int		i;
	int		j;
	t_pnt	**map;
	t_pnt	**rmap;
	int		d;

	d = mlx->zmax - mlx->zmin;
	j = 0;
	i = 0;
	map = fdf->map;
	rmap = fdf->rmap;
	while (i < mlx->rlen)
	{
		while (j < mlx->clen)
		{
			ft_calc_math(&map[i][j], &rmap[i][j], ang, fdf);
			rmap[i][j].color = ft_rgb_itp(*mlx->zmin, *mlx->zmax,
			map[i][j].z * mlx->height);
			j++;
		}
		j = 0;
		i++;
	}
}
