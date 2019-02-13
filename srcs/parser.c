/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:03:22 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:44:48 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static int	total_value(int *len_x, int ilen)
{
	int		i;
	int		total_value;

	i = 0;
	total_value = 0;
	while (i < ilen)
		total_value += len_x[i++];
	return (total_value);
}

static int	convert_int(const char *line, int **int_line, double len)
{
	int		i;

	if (!(*int_line = (int*)ft_memalloc(sizeof(int) * len)))
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

int			parser(int const fd, t_map *map)
{
	char	*line;
	int		*int_line;
	int		ret;
	int		ilen;
	int		*tmp;

	map->width = 0;
	map->height = 0;
	ilen = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(map->len_x = ft_addint(map->len_x, ft_countnumbers(line), ilen)))
			return (-2);
		if ((ret = convert_int(line, &int_line, map->len_x[ilen])) <= 0)
			return (ret);
		tmp = map->tab;
		if (!(map->tab = ft_catinttab(map->tab, total_value(map->len_x, ilen), int_line, map->len_x[ilen])))
			return (-2);
		ft_tabintdel(&tmp);
		ft_strdel(&line);
		ft_tabintdel(&int_line);
		ilen++;
	}
	return ((ret < 0) ? -4 : 1);
}
