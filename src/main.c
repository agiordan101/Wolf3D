/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:26:02 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 20:50:31 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int init(t_win *win, t_map *map, t_calculs *calculs, t_player *player)
{
	map->tab = NULL;
	map->len_x = NULL;
	win->width = 1200;
	win->height = 1200;
	if (!(calculs->dist = (double *)malloc(sizeof(double) * win->width)))
		return (1);
	player->pos.x = 2.5;
	player->pos.y = 3.5;
	player->vel = (t_vector_2d){.x = 0.1, .y = 0.1};
	player->dir = -PI / 2;
	player->fov = PI / 2;
	return (0);
}

int		main(int ac, char **av)
{
	t_win	win;
	int		fd;
	int		ret;

	if (ac == 3)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)  
			return (error(-1, "open"));
		if (ft_atoi(av[2]) == 0)
		{
			if (init(&win, &(win.map), &(win.calculs), &(win.player)))
				return (error(-2, "init"));
			if ((ret = parser(fd, &(win.map))) <= 0)
				return(error(ret, "parser"));
		}
		else if (ft_atoi(av[2]) == 1)
		{
			map_editor(fd);
			printf("map_editor\n");
		}
		open_window(&win);
		window_loop(&win);
		quit(&win);
	}
	else
		ft_putendl("usage: ./Wolf3D <map> <0/1>\n0 : Wolf3d\n1 : map_editor");
	return (0);
}
