/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:02:39 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/02 20:13:09 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	deal_key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	return (0);
}

// static int	ft_get_llen()
// {
// 	return (0);
// }

static t_pnt	**ft_get_input(char *filename, t_grh *mlx)
{
	t_pnt	**map;

	map = ft_fdf_catch_input(filename, mlx);
	//mlx->llen = ft_get_llen(mlx);
	return (map);
}

int			main(int argc, char **argv)
{
	t_grh	*mlx;
	t_pnt	**map;

	mlx = (t_grh *)malloc(sizeof(t_grh));
	// if (argc != 2)
	// {
	// 	ft_putendl("Usage: ./a.out [map file]");
	// 	return (0);
	// }
	(void)argv;
	(void)argc;
	map = ft_get_input("test_maps/elem.fdf", mlx);
	if (map == NULL)
	{
		ft_putstr("Found wrong line length. Exiting\n");
		return (0);
	}
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1000, 1000, "FDF");
	//ft_show_map(mlx, map);
	mlx_key_hook(mlx->win, deal_key, (void *)0);
	mlx_loop(mlx->mlx);
	return (0);
}
