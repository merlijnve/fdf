/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_show_ui.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/11 18:03:20 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/26 22:02:09 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Draws square
*/

void	ft_draw_square(int x, int y, int size, t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			ft_imgpxlput(fdf, 0x0, i + x, j + y);
			j++;
		}
		j = 0;
		i++;
	}
}

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
			ft_imgpxlput(fdf, color, x + j, y + i);
			j++;
		}
		j = 0;
		i++;
	}
}

/*
**	Drawing the arrow buttons for rotating
*/

void	ft_draw_arrow_buttons(t_fdf *fdf, int x, int y)
{
	t_grh *mlx;

	mlx = fdf->mlx;
	ft_draw_button(x, y + 450, " < ", fdf);
	ft_draw_button(x + 80, y + 450, " > ", fdf);
	ft_draw_button(x, y + 500, " < ", fdf);
	ft_draw_button(x + 80, y + 500, " > ", fdf);
	ft_draw_button(x, y + 550, " < ", fdf);
	ft_draw_button(x + 80, y + 550, " > ", fdf);
	ft_draw_button(x, y + 650, " /\\ ", fdf);
	ft_draw_button(x, y + 690, " \\/ ", fdf);
	ft_draw_button(x, y + 750, " /\\ ", fdf);
	ft_draw_button(x, y + 790, " \\/ ", fdf);
}

/*
**	Updating all the angles
*/

void	ft_show_angles(t_fdf *fdf)
{
	t_grh	*mlx;
	t_ang	*ang;
	char	*x;
	char	*y;
	char	*z;

	mlx = fdf->mlx;
	ang = fdf->ang;
	x = ft_itoa(ang->x);
	y = ft_itoa(ang->y);
	z = ft_itoa(ang->z);
	mlx_string_put(mlx->mlx, mlx->win, 200, 500, 0xffffff, x);
	mlx_string_put(mlx->mlx, mlx->win, 200, 550, 0xffffff, y);
	mlx_string_put(mlx->mlx, mlx->win, 200, 600, 0xffffff, z);
	free(x);
	free(y);
	free(z);
}

/*
**	drawing the menu
*/

void	ft_show_ui(t_fdf *fdf)
{
	int		x;
	int		y;

	x = 50;
	y = 50;
	ft_draw_button(x, y, "View 1 ", fdf);
	ft_draw_button(x, y + 50, "Turn upside down", fdf);
	ft_draw_button(x, y + 100, "Top view", fdf);
	ft_draw_button(x, y + 300, "Isometric view ", fdf);
	ft_draw_button(x, y + 350, "Rotate speed 4x ", fdf);
	mlx_string_put(fdf->mlx->mlx, fdf->mlx->win, x, y + 410, 0xffffff,
	"Rotating:    Degrees:");
	ft_draw_arrow_buttons(fdf, x, y);
	ft_show_angles(fdf);
	if (fdf->flag->i == 1)
		ft_draw_square(216, 359, 8, fdf);
	if (fdf->flag->r == 8)
		ft_draw_square(230, 409, 8, fdf);
}
