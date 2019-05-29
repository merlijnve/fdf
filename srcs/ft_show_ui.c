/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_show_ui.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/11 18:03:20 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/29 20:05:00 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	UI Button drawing
**	-	draws square and shows text according to the length of the text
*/

void	ft_draw_button(int x, int y, char *s, t_fdf *fdf)
{
	int		len;
	int		i;
	int		j;
	int		color;

	j = 0;
	i = 0;
	len = 10 * ft_strlen(s) + 3 * (ft_strlen(s) - 2);
	while (i < 30)
	{
		color = 0x5b5b5b;
		while (j < len)
		{
			if (j >= 3)
				color = 0xdadfe1;
			if (i > 25)
				color = 0x5b5b5b;
			mlx_pixel_put(fdf->mlx->mlx, fdf->mlx->win, x + j, y + i, color);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_string_put(fdf->mlx->mlx, fdf->mlx->win, x + ft_strlen(s), y, 0, s);
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
	ft_draw_button(x, y, "Viewpoint 1", fdf);
	ft_draw_button(x, y + 50, "Viewpoint 2", fdf);
	ft_draw_button(x, y + 100, "Top view", fdf);
	ft_draw_button(x, y + 300, "Isometric view", fdf);
}