/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 18:02:55 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/11 19:18:15 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "math.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		x;
	int		y;
	int		d;
	int		i;
}				t_line;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
	int		r;
	int		g;
	int		b;
}				t_pnt;

typedef struct	s_grh
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*adr;
	int		rlen;
	int		clen;
	int		scale;
	int		yf;
	int		ef;
	t_pnt	*zmax;
	t_pnt	*zmin;
	int		ymi;
	int		yma;
	int		xma;
	int		xmi;
	int		height;
	int		zoom;
}				t_grh;

typedef struct	s_angles
{
	double	x;
	double	y;
	double	z;
}				t_ang;

typedef struct	s_flag
{
	int		i;
	int		mpd;
	int		ix;
	int		iy;
	double	r;
}				t_fl;

typedef struct	s_fdf
{
	t_ang	*ang;
	t_pnt	**map;
	t_pnt	**rmap;
	t_grh	*mlx;
	t_fl	*flag;
}				t_fdf;

void			ft_drawline(t_pnt p0, t_pnt p1, t_fdf *fdf);
void			ft_calc_points(t_grh *mlx, t_fdf *fdf, t_ang *ang);
t_pnt			**ft_fdf_catch_input(char *filename, t_grh *mlx);
void			ft_draw_map(t_fdf *fdf);
void			ft_translate_map(t_grh *mlx, t_pnt **map, int xt, int yt);
void			ft_connect_dots(t_fdf *fdf, t_pnt **map);
void			ft_show_ui(t_fdf *fdf);
void			ft_translate_mid(t_fdf *fdf, t_pnt **rmap);
int				ft_mrelease(int button, int x, int y, t_fdf *fdf);
int				ft_mpress(int button, int x, int y, t_fdf *fdf);
void			ft_preset_views(int key, t_fdf *fdf);
int				ft_mmove(int x, int y, t_fdf *fdf);
int				ft_keypress(int key, t_fdf *fdf);
int				ft_mpress(int button, int x, int y, t_fdf *fdf);
void			ft_draw_button(int x, int y, char *s, t_fdf *fdf);
int				ft_rgb_itp(t_pnt p0, t_pnt p1, int x);
void			ft_arrow_keys(int key, t_fdf *fdf);
void			ft_imgpxlput(t_fdf *fdf, int color, int x, int y);
void			ft_show_txt(t_fdf *fdf);

#endif
