/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:02:39 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/04/18 21:43:45 by mvan-eng      ########   odam.nl         */
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

int	ft_make_map(char *filename)
{
	t_row *map;
	t_col *test;

	map = ft_fdf_catch_input(filename);
	if (map == NULL)
		return (-1);
	map = map->next;
	map = map->next;
	test = map->c;
	while (test != NULL)
	{
		printf("x: %d, y: %d, z: %d\n", test->x, test->y, test->z);
		test = test->next;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		d;
	int		e;

	d = 400;
	e = 400;
	// if (argc != 2)
	// {
	// 	ft_putendl("Usage: ./a.out [map file]");
	// 	return (0);
	// }
	(void)argv;
	(void)argc;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "FDF");
	mlx_key_hook(win, deal_key, (void *)0);
	if (ft_make_map("test_maps/elem.fdf") == -1)
	{
		ft_putstr("Found wrong line length. Exiting\n");
		return (0);
	}
	dot_line(400, 250, 400, 550, 0x00ffff, mlx, win);
	dot_line(250, 400, 550, 400, 0x00ffff, mlx, win);
	mlx_loop(mlx);
	return (0);
}
