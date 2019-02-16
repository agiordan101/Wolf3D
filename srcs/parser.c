/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:03:22 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 22:58:37 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int			parser_error(int error)
{
	write(1, "Error : ", 8);
	if (error == -1)
		return(write(1, "Openning Failed, Please enter a valid file name\n", 48));
	else if (error == -2)
		return(write(1, "Malloc Failed\n", 14));
	else if (error == -3)
		return(write(1, "File must contain only spaces and numbers between 0 and 9\n", 58));
	else if (error == -4)
		return(write(1, "Get_next_line Failed\n", 21));
	else
		return(write(1, "Undefined\n",  10));
}

int			sum_x(t_map *map, int iwanted)
{
	int	i;
	int	sum_x;

	i = 0;
	sum_x = 0;
	while (i < iwanted)
		sum_x += map->len_x[i++];
	return (sum_x);
}

static int	convert_int(const char *line, int **int_line, double len)
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

/*static int	convert_int(const char *line, int **int_line, double len)
{
	char	**tab;
	int		i;

	if (!(*int_line = (int *)ft_memalloc(sizeof(int) * len)))
		return (-2);
	tab = ft_strsplit(line, ' '); // leaks sale pute d'antoine. ok.
	i = -1;
	while (tab[++i])
		(*int_line)[i] = ft_atoi(tab[i]);
	return (1);
}*/

int			parser(int const fd, t_map *map)
{
	char	*line;
	int		*int_line;
	int		*tmp;
	int		ret;
	int		i;

	int_line = NULL;
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(map->len_x = ft_addint(map->len_x, ft_countnumbers(line), i)))
			return (-2);
		printf("Line : %s\n", line);
		if ((ret = convert_int(line, &int_line, map->len_x[i])) <= 0)
			return (ret);
		tmp = map->tab;
		if (!(map->tab = ft_catinttab(map->tab,
							sum_x(map, i), int_line, map->len_x[i])))
			return (-2);
		ft_putinttab(int_line, map->len_x[i]);
		ft_tabintdel(&tmp);
		ft_strdel(&line);
		ft_tabintdel(&int_line);
		i++;
	}
	map->len_y = i;
	
	return ((ret < 0) ? -4 : 1);
}
