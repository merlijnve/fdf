/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_show_ui.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/11 18:03:20 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/29 13:39:39 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	UI Button drawing
**	-	draws square and shows text according to the length of the text
*/

void	ft_draw_button(int x, int y, char *s, int c, t_fdf *fdf)
{
	int		len;
	int		i;
	int		j;
	t_grh	*mlx;
	int		color;

	mlx = fdf->mlx;
	j = 0;
	i = 0;
	len = 10 * ft_strlen(s) + 4 * (ft_strlen(s) - 2);
	while (i < 30)
	{
		color = 0x5b5b5b;
		while (j < len)
		{
			if (j >= 3)
				color = c;
			if (i > 25)
				color = 0x5b5b5b;
			mlx_pixel_put(mlx->mlx, mlx->win, x + j, y + i, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_string_put(mlx->mlx, mlx->win, x + 2 * (ft_strlen(s) - 2), y, 0x0, s);
}

/*
**	Mouse release handling
*/

int		ft_mrelease(int button, int x, int y, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx->mlx, fdf->mlx->win);
	if (x > 50 && x < 196 && y > 50 && y < 75)
		ft_preset_views(1, fdf);
	if (x > 50 && x < 196 && y > 100 && y < 125)
		ft_preset_views(2, fdf);
	if (x > 50 && x < 196 && y > 150 && y < 175)
		ft_preset_views(3, fdf);
	if (x > 50 && x < 196 && y > 350 && y < 375)
	{
		fdf->flag->i *= -1;
		ft_preset_views(4, fdf);
	}
	if (button == 2)
		ft_draw_button(x, y, "Made my mvan-eng", 0xffffff, fdf);
	ft_calc_points(fdf->mlx, fdf, fdf->ang);
	ft_draw_map(fdf);
	fdf->flag->mpd = 0;ß
	return (0);
}

/*
**	drawing the menu
*/

void	ft_show_ui(t_fdf *fdf)
{
	int x;
	int y;

	x = 50;
	y = 50;
	ft_draw_button(x, y, "Viewpoint 1", 0xdadfe1, fdf);
	ft_draw_button(x, y + 50, "Viewpoint 2", 0xdadfe1, fdf);
	ft_draw_button(x, y + 100, "Top view", 0xdadfe1, fdf);
	ft_draw_button(x , y + 300, "Isometric view", 0xdadfe1, fdf);
}
