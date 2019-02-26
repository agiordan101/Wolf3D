/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gal <gal@student.le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:03:22 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 16:49:42 by gal         ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int **ft_addinttabn(int **tab, int len_y, int *len_x, int *line)
{
	int **ntab;
	int i;
	int j;

	if (!(ntab = (int **)ft_memalloc(sizeof(int *) * (len_y + 1))))
		return (NULL);
	i = 0;
	while (i < len_y)
	{
		if (!(ntab[i] = (int *)ft_memalloc(sizeof(int) * len_x[i])))
			return (NULL);
		j = 0;
		while (j < len_x[i])
		{
			ntab[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	if (!(ntab[i] = (int *)ft_memalloc(sizeof(int) * len_x[i])))
		return (NULL);
	j = -1;
	while (++j < len_x[i])
		ntab[i][j] = line[j];
	return (ntab);
}

static int	convert_int(const char *line, int **int_line, int len)
{
	int		i;

	if (!(*int_line = (int *)ft_memalloc(sizeof(int) * len)))
		return (-2);
	i = 0;
	while (i < len)
	{
		if (*line == ' ')
			line++;
		else if (ft_isdigit(*line))
		{
			(*int_line)[i++] = ft_atoi(line);
			while (ft_isdigit(*line) && *line)
				line++;
		}
		else
			return (-3);
	}
	return (1);
}

int parser(int const fd, t_map *map)
{
	char *line;
	int *int_line;
	int ret;
	int error;
	int **tmp;

	map->len_y = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		map->len_x = ft_addint(map->len_x, (double)ft_countnumbers(line), map->len_y);
		if ((error = convert_int(line, &int_line, map->len_x[map->len_y])) <= 0)
			return (error);
		tmp = map->tab;
		map->tab = ft_addinttabn(map->tab, map->len_y, map->len_x, int_line);
		ft_tabint2del(&tmp, map->len_y);
		map->len_y++;
		ft_tabintdel(&int_line);
		ft_strdel(&line);
	}
	return ((ret < 0) ? -4 : 1);
}
