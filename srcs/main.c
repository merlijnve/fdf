/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:02:39 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/28 11:20:36 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_initialize_rmap(t_fdf *fdf)
{
	int		i;
	int		j;
	t_pnt	**rmap;
	t_grh	*mlx;

	mlx = fdf->mlx;
	i = 0;
	j = 0;
	fdf->rmap = (t_pnt **)malloc(sizeof(t_pnt *) * mlx->rlen);
	rmap = fdf->rmap;
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
}

static int	ft_initialize(t_grh *mlx, char *filename, t_fdf *fdf)
{
	int temp;

	temp = 0;
	fdf->mlx = mlx;
	fdf->mlx->yf = 0;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1800, 1300, "FDF");
	mlx->img = mlx_new_image(mlx->mlx, 1800, 1300);
	mlx->adr = mlx_get_data_addr(mlx->img, &temp, &temp, &temp);
	fdf->flag = (t_fl *)malloc(sizeof(t_fl));
	fdf->flag->i = -1;
	fdf->flag->mpd = 0;
	fdf->flag->r = 2;
	fdf->mlx->zoom = 1;
	fdf->map = ft_fdf_catch_input(filename, mlx);
	if (fdf->map == NULL)
	{
		ft_putstr("Found wrong line length. Exiting\n");
		return (-1);
	}
	ft_initialize_rmap(fdf);
	ft_calc_points(mlx, fdf, fdf->ang);
	ft_draw_map(fdf);
	return (0);
}

/*
** Hooks keypress, mousepress, mouserelease and mousemove
*/

static void	ft_setup_controls(t_fdf *fdf)
{
	t_grh *mlx;

	mlx = fdf->mlx;
	mlx_hook(mlx->win, 2, 0, ft_keypress, fdf);
	mlx_hook(mlx->win, 4, 0, ft_mpress, fdf);
	mlx_hook(mlx->win, 5, 0, ft_mrelease, fdf);
}

/*
**	Initializes grids, hooks controls, sets loop.
*/

int			main(int argc, char **argv)
{
	t_grh	*mlx;
	t_fdf	*fdf;
	t_ang	*ang;

	if (argc != 2)
	{
		ft_putendl("Usage: ./a.out [map file]");
		return (0);
	}
	ang = (t_ang *)malloc(sizeof(t_ang));
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	mlx = (t_grh *)malloc(sizeof(t_grh));
	ang->x = 0;
	ang->y = 0;
	ang->z = 0;
	fdf->ang = ang;
	if (ft_initialize(mlx, argv[1], fdf) == -1)
		return (0);
	ft_setup_controls(fdf);
	mlx_loop(mlx->mlx);
	return (0);
}
