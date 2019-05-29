/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fdf_catch_input.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:34:01 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/29 20:27:32 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Counts the amount of pointers in a null terminated memory block
*/

static int		ft_count_pointers(char **p)
{
	int c;

	c = 0;
	while (p[c] != NULL)
		c++;
	return (c);
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
		if (mlx->rlen == 0)
			mlx->clen = ft_count_pointers(ft_strsplit(line, ' '));
		if (mlx->clen != ft_count_pointers(ft_strsplit(line, ' ')))
			return (-1);
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
	mlx->scale = 800 / t;
	mlx->height = 30;
	while (split[i] != NULL)
	{
		row[i].x = mlx->scale * i;
		row[i].y = mlx->scale * c;
		row[i].z = mlx->height * ft_atoi(split[i]);
		row[i].color = 0x00fff + 10 * row[i].z;
		i++;
	}
	free(split);
	return (row);
}

/*
**	Reads a line from given File Descriptor
**	(Creates columnsß)
*/

static t_pnt	**ft_setup_grid(int fd, t_grh *mlx)
{
	t_pnt	**map;
	int		i;
	char	*line;

	i = 0;
	map = (t_pnt **)malloc(sizeof(int *) * (mlx->rlen + 1));
	map[mlx->rlen] = NULL;
	while (i < mlx->rlen)
	{
		get_next_line(fd, &line);
		map[i] = ft_line_to_nrs(line, mlx, i);
		i++;
	}
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
