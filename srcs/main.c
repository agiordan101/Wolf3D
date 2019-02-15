/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:26:02 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 17:22:12 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		init(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->tab = NULL;
	map->len_x = NULL;
	return (0);
}

int		main(int ac, char **av)
{
	t_map	map;
	int		fd;
	int		ret;
	int		i;
	int		j;

	if (ac == 2)
	{
		if (init(&map))
		{
			ft_putendl("Error initialisation");
			return (1);
		}
		if ((fd = open(av[1], O_RDONLY)) < 0)  
			return (parser_error(-1));
		ft_putendl("file opened");
		if ((ret = parser(fd, &map)) <= 0)
			return(parser_error(ret));
		ft_putendl("parsing finished");
		i = -1;
		while (++i < 10)
		{
			j = -1;
			while (++j < 10)
				printf("%i", map.tab[i * 10 + j]);
			printf("\n");
		}
	}
	else
		ft_putendl("./wolf3d map\n");
	return (0);
}
