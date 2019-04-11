/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:02:39 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/04/11 12:49:13 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	deal_key(int key, void *param)
{
	if (key == 53)
		exit(0);
	return (0);
}

int			main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	char	**map;
	int		d;
	int		e;

	d = 400;
	e = 400;
	if (argc != 2)
	{
		ft_putendl("Usage: ./a.out [map file]");
		return (0);
	}
	//map = ft_create_imap(argv[1]);
	//ft_putcmap(map);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "Getting started with mlX");
	dot_line(d + 0, e - 150, d + 0, e + 150, 0x00ffff, mlx, win);
	dot_line(d - 150, e + 0, d + 150, e + 0, 0x00ffff, mlx, win);
	mlx_key_hook(win, deal_key, (void *)0);
	mlx_loop(mlx);
}
