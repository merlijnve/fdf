/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:02:39 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/04/04 18:38:05 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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
	int		p0[2];
	int		p1[2];

	p0[0] = 200;
	p0[1] = 200;
	p1[0] = 450;
	p1[1] = 190;
	if (argc != 2)
	{
		ft_putendl("Usage: ./a.out [map file]");
		return (0);
	}
	//map = ft_create_imap(argv[1]);
	//ft_putcmap(map);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Getting started with mlX");
	ft_drawline(p0[0], p0[1], p1[0], p1[1], mlx, win);
	mlx_pixel_put(mlx, win, p0[0], p0[1], 0xff0000);
	mlx_pixel_put(mlx, win, p1[0], p1[1], 0xff0000);
	mlx_key_hook(win, deal_key, (void *)0);
	mlx_loop(mlx);
}