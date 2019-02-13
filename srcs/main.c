/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:26:02 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 18:42:39 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		main(int ac, char **av)
{
	t_map	map;
	int		fd;
	int		ret;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0 || (ret = parser(fd, &map)) <= 0)
			return (0);
		ft_intput(map.tab, 100);
	}
	return (0);
}
