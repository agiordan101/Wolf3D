/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:03:22 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 17:03:53 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int	convert_int(const char *line, int **int_line, double size_j)
{
	int		i;

	if (!(*int_line = (int*)ft_memalloc(sizeof(int) * size_j)))
		return (-1);
	i = 0;
	while (i < size_j)
	{
		if (*line == ' ')
			line++;
		else if (ft_isdigit(*line) || *line == '-' || *line == '+')
		{
			(*int_line)[i++] = ft_atoi(line);
			if (*line == '-' || *line == '+')
				line++;
			if (ft_isdigit(*line))
				while (ft_isdigit(*line) && *line)
					line++;
			else
				return (-3);
		}
		else
			return (-3);
	}
	return (1);
}

int			parser(int const fd, t_map *amap)
{
	char	*line;
	int		*int_line;
	int		ret;
	int		error;
	int		**tmp;

	amap->size.i = 0.0;
	amap->size.j = 0.0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (amap->size.i == 0)
			amap->size.j = (double)ft_countnumbers(line);
		if ((ft_countnumbers((char*)line)) != amap->size.j)
			return (-2);
		if ((error = convert_int(line, &int_line, amap->size.j)) <= 0)
			return (error);
		tmp = amap->tab;
		amap->tab = ft_2dintpushback(amap->tab,
				amap->size.i, amap->size.j, int_line);
		ft_2dintdel(&tmp, amap->size.i);
		amap->size.i++;
		ft_intdel(&int_line);
		ft_strdel(&line);
	}
	return ((ret < 0) ? -4 : 1);
}
