/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:02:39 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/06 20:23:15 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_initialize_rmap(t_fdf *fdf)
{
	int		i;
	int		j;
	t_pnt	**rmap;
	t_grh	*mlx;

	mlx = fdf->mlx;
	i = 0;
	j = 0;
	rmap = (t_pnt **)malloc(sizeof(t_pnt *) * mlx->rlen);
	while (i < mlx->rlen)
	{
		rmap[i] = (t_pnt *)malloc(sizeof(t_pnt) * mlx->clen);
		while (j < mlx->clen)
		{
			rmap[i][j].x = 0;
			rmap[i][j].y = 0;
			rmap[i][j].z = 0;
			j++;
		}
		j = 0;
		i++;
	}
	fdf->rmap = rmap;
}

static int		ft_initialize(t_grh *mlx, char *filename, t_fdf *fdf)
{
	fdf->map = ft_fdf_catch_input(filename, mlx);
	if (fdf->map == NULL)
	{
		ft_putstr("Found wrong line length. Exiting\n");
		return (-1);
	}
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1800, 1300, "FDF");
	fdf->mlx = mlx;
	ft_initialize_rmap(fdf);
	fdf->mlx = mlx;
	fdf->flag = (t_fl *)malloc(sizeof(t_fl));
	fdf->flag->i = -1;
	fdf->flag->mpd = 0;
	fdf->flag->r = 2;
	fdf->mlx->yf = 0;
	fdf->mlx->zoom = 1;
	ft_calc_points(mlx, fdf, fdf->ang);
	ft_draw_map(fdf);
	return (0);
}

/*
** Hooks keypress, mousepress, mouserelease and mousemove
*/

static void		ft_setup_controls(t_fdf *fdf)
{
	t_grh *mlx;

	mlx = fdf->mlx;
	mlx_hook(mlx->win, 2, 0, ft_keypress, fdf);
	mlx_hook(mlx->win, 4, 0, ft_mpress, fdf);
	mlx_hook(mlx->win, 5, 0, ft_mrelease, fdf);
	mlx_hook(mlx->win, 6, 0, ft_mmove, fdf);
}

/*
**	Initializes grids, hooks controls, sets loop.
*/

int				main(int argc, char **argv)
{
	t_grh	*mlx;
	t_fdf	*fdf;
	t_ang	*ang;

	ang = (t_ang *)malloc(sizeof(t_ang));
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	mlx = (t_grh *)malloc(sizeof(t_grh));
	ang->x = 0;
	ang->y = 0;
	ang->z = 30;
	fdf->ang = ang;
	if (argc != 2)
	{
		ft_putendl("Usage: ./a.out [map file]");
		return (0);
	}
	if (ft_initialize(mlx, argv[1], fdf) == -1)
		return (0);
	ft_setup_controls(fdf);
	mlx_loop(mlx->mlx);
	return (0);
}
