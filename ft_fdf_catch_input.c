/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fdf_catch_input.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 17:37:50 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/04/18 21:45:04 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_col_count(char *line)
{
	int		i;
	char	**row;

	i = 0;
	row = ft_strsplit(line, ' ');
	while (row[i] != NULL)
		i++;
	return (i);
}

t_col		*ft_initialize_cols(char *line, t_row *r, int rownr)
{
	t_col		*c;
	static int	len;
	int			i;
	t_col		*d;
	char		**row;

	i = 0;
	(void)r;
	if (len == 0)
		len = ft_col_count(line);
	if (ft_col_count(line) != len)
		return (NULL);
	c = (t_col *)malloc(sizeof(t_col));
	if (c == NULL)
		return (NULL);
	d = c;
	row = ft_strsplit(line, ' ');
	while (i < len)
	{
		if (i < (len - 1))
			d->next = (t_col *)malloc(sizeof(t_col));
		d->x = i;
		d->y = rownr;
		d->z = ft_atoi(row[i]);
		d = d->next;
		i++;
	}
	return (c);
}

t_row		*ft_fdf_catch_input(char *filename)
{
	char	*line;
	t_row	*r;
	t_row	*d;
	int		fd;
	int		rownr;

	rownr = 0;
	fd = open(filename, O_RDWR);
	r = (t_row *)malloc(sizeof(t_row));
	d = r;
	if (r == NULL)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		r->c = ft_initialize_cols(line, r, rownr);
		r->next = (t_row *)malloc(sizeof(t_row));
		if (r->c == NULL || r->next == NULL)
			return (NULL);
		r = r->next;
		rownr++;
	}
	return (d);
}
