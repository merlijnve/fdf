/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_drawline.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 13:41:30 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/04/15 18:55:30 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(0);
	return (0);
}

static void	ft_drawline_h(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
	t_line line;
	
	line.dx = x1 - x0;
	line.dy = y1 - y0;
	line.i = 1;
	if (line.dx < 0)
	{
		line.i = -1;
		line.dx = line.dx * -1;
	}
	line.d = 2 * line.dx - line.dy;
	line.x = x0;
	line.y = y0;
	while (line.y <= y1)
	{
		mlx_pixel_put(mlx, win, line.x, line.y, 0xffffff);
		if (line.d > 0)
		{
			line.x += line.i;
			line.d -= 2 * line.dy;
		}
		line.d += 2 * line.dx;
		line.y++;
	}
}

static void	ft_drawline_l(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
	t_line line;
	
	line.dx = x1 - x0;
	line.dy = y1 - y0;
	line.i = 1;
	if (line.dy < 0)
	{
		line.i = -1;
		line.dy = line.dy * -1;
	}
	line.d = 2 * line.dy - line.dx;
	line.y = y0;
	line.x = x0;
	while (line.x <= x1)
	{
		mlx_pixel_put(mlx, win, line.x, line.y, 0xffffff);
		if (line.d > 0)
		{
			line.y += line.i;
			line.d -= 2 * line.dx;
		}
		line.d += 2 * line.dy;
		line.x++;
	}
}

void  		  ft_drawline(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
	if (abs(y1 - y0) < abs(x1 - x0))
	{
		if (x0 > x1)
			ft_drawline_l(x1, y1, x0 , y0, mlx, win);
		else
			ft_drawline_l(x0, y0, x1 , y1, mlx, win);
	}
	else
	{
		if (y0 > y1)
			ft_drawline_h(x1, y1, x0 , y0, mlx, win);
		else
			ft_drawline_h(x0, y0, x1 , y1, mlx, win);
	}
}
