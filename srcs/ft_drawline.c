/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_drawline.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 13:41:30 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/06 19:41:08 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_rgb_itp(t_pnt p0, t_pnt p1, int x)
{
	int		d;
	double	dx;
	int		r;
	int		g;
	int		b;

	dx = p0.x - p1.x;
	if (dx == 0)
		dx = 0.01;
	d = (p1.x - x) / dx;
	p0.r = p0.color / pow(256, 2);
	p0.g = (p0.color / 256) % 256;
	p0.b = p0.color % 256;
	p1.r = p1.color / pow(256, 2);
	p1.g = (p1.color / 256) % 256;
	p1.b = p1.color % 256;
	r = p0.r + (p1.r - p0.r) * x;
	g = p0.g + (p1.g - p0.g) * x;
	b = p0.b + (p1.b - p0.b) * x;
	r = pow(256, 2) * r + 256 * g + b;
	return (r);
}

static void	ft_drawline_h(t_pnt p0, t_pnt p1, t_pnt c, t_grh *mlx)
{
	t_line	line;

	line.dx = p1.x - p0.x;
	line.dy = p1.y - p0.y;
	line.i = 1;
	if (line.dx < 0)
	{
		line.i = -1;
		line.dx = line.dx * -1;
	}
	line.d = 2 * line.dx - line.dy;
	line.x = p0.x;
	line.y = p0.y;
	while (line.y <= p1.y)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, line.x, line.y, c.color);
		if (line.d > 0)
		{
			line.x += line.i;
			line.d -= 2 * line.dy;
		}
		line.d += 2 * line.dx;
		line.y++;
	}
}

static void	ft_drawline_l(t_pnt p0, t_pnt p1, t_pnt c, t_grh *mlx)
{
	t_line line;

	line.dx = p1.x - p0.x;
	line.dy = p1.y - p0.y;
	line.i = 1;
	if (line.dy < 0)
	{
		line.i = -1;
		line.dy = line.dy * -1;
	}
	line.d = 2 * line.dy - line.dx;
	line.y = p0.y;
	line.x = p0.x;
	while (line.x <= p1.x)
	{
		mlx_pixel_put(mlx->mlx, mlx->win, line.x, line.y, c.color);
		if (line.d > 0)
		{
			line.y += line.i;
			line.d -= 2 * line.dx;
		}
		line.d += 2 * line.dy;
		line.x++;
	}
}

void		ft_drawline(t_pnt p0, t_pnt p1, t_grh *mlx)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			ft_drawline_l(p1, p0, p0, mlx);
		else
			ft_drawline_l(p0, p1, p0, mlx);
	}
	else
	{
		if (p0.y > p1.y)
			ft_drawline_h(p1, p0, p0, mlx);
		else
			ft_drawline_h(p0, p1, p0, mlx);
	}
}
