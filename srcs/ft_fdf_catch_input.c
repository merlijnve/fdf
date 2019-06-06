/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fdf_catch_input.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:34:01 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/06/06 20:29:35 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Find max z-value, used for color
*/

int				ft_extr(t_pnt **map, t_grh *mlx)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (mlx->yf == 0)
	{
		mlx->zmax = &map[0][0];
		mlx->zmin = &map[0][0];
		mlx->yf = 1;
	}
	while (i < mlx->rlen)
	{
		while (j < mlx->clen)
		{
			if (map[i][j].z > mlx->zmax->z)
				mlx->zmax = &map[i][j];
			if (map[i][j].z < mlx->zmin->z)
				mlx->zmin = &map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

/*
**	Counts columns and rows, saves to mlx->clen and mlx->rlen (columns, rows)
*/

static int		ft_count_grid(int fd, t_grh *mlx)
{
	char	*line;
	int		ret;

	ret = 1;
	mlx->rlen = 0;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (-1);
		if (mlx->rlen == 0)
			mlx->clen = ft_count_pointers(ft_strsplit(line, ' '));
		if (ret == 1 && mlx->clen != ft_count_pointers(ft_strsplit(line, ' ')))
			return (-1);
		if (ret == 1)
			ft_strdel(&line);
		mlx->rlen++;
	}
	mlx->rlen--;
	return (0);
}

/*
** Converts line to array of points, consisting of a X, Y and Z value fittingly
** (Creates row)
*/

static t_pnt	*ft_line_to_nrs(char *line, t_grh *mlx, int c)
{
	char	**split;
	t_pnt	*row;
	int		i;
	int		t;

	i = 0;
	row = (t_pnt *)malloc(sizeof(t_pnt) * mlx->clen);
	split = ft_strsplit(line, ' ');
	t = (mlx->clen > mlx->rlen) ? mlx->clen : mlx->rlen;
	mlx->xscale = 1000 / t;
	mlx->height = 25;
	while (split[i] != NULL)
	{
		row[i].x = mlx->xscale * i;
		row[i].y = mlx->xscale * c;
		row[i].z = ft_atoi(split[i]);
		ft_strdel(split);
		i++;
	}
	return (row);
}

/*
**	Reads a line from given File Descriptor
**	(Creates columns)
*/

static t_pnt	**ft_setup_grid(int fd, t_grh *mlx)
{
	t_pnt	**map;
	int		i;
	char	*line;
	int		ret;

	ret = 0;
	i = 0;
	map = (t_pnt **)malloc(sizeof(int *) * (mlx->rlen + 1));
	map[mlx->rlen] = NULL;
	while (i < mlx->rlen)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (NULL);
		map[i] = ft_line_to_nrs(line, mlx, i);
		ft_strdel(&line);
		i++;
	}
	ft_extr(map, mlx);
	mlx->zmax->color = 0xffff00;
	mlx->zmin->color = 0xffffff;
	return (map);
}

t_pnt			**ft_fdf_catch_input(char *filename, t_grh *mlx)
{
	int		fd;
	t_pnt	**map;

	fd = open(filename, O_RDONLY);
	if (ft_count_grid(fd, mlx) == -1)
		return (NULL);
	close(fd);
	fd = open(filename, O_RDONLY);
	map = ft_setup_grid(fd, mlx);
	if (map == NULL)
		return (NULL);
	return (map);
}
