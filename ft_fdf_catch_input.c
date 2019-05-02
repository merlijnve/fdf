/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fdf_catch_input.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 15:34:01 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/05/02 20:07:01 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_count_pointers(char **p)
{
	int c;

	c = 0;
	while (p[c] != NULL)
		c++;
	return (c);
}

static t_pnt	*ft_line_to_nrs(char *line, t_grh *mlx, int c)
{
	char	**split;
	t_pnt	*row;
	int		i;

	i = 0;
	row = (t_pnt *)malloc(sizeof(t_pnt) * mlx->clen);
	split = ft_strsplit(line, ' ');
	while (split[i] != NULL)
	{
		row[i].x = i;
		row[i].y = c;
		row[i].z = ft_atoi(split[i]);
		i++;
	}
	return (row);
}

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
	return (0);
} 

static t_pnt		**ft_setup_grid(int fd, t_grh *mlx)
{
	t_pnt		**map;
	int		i;
	char	*line;

	i = 0;
	map = (t_pnt **)malloc(sizeof(int *) * (mlx->rlen + 1));
	map[mlx->rlen] = NULL;
	while (i < mlx->rlen - 1)
	{
		get_next_line(fd, &line);
		map[i] = ft_line_to_nrs(line, mlx, i);
		i++;
	}
	return (map);
}

t_pnt		**ft_fdf_catch_input(char *filename, t_grh *mlx)
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
