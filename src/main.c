/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:26:02 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 17:07:55 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int init(t_win *win, t_map *map, t_calculs *calculs, t_player *player)
{
	win->width = 1200;
	win->height = 1200;
	map->minimap.x = win->width / 20;
	map->minimap.y = win->height / 20;
	map->minimap.width = win->width / 5;
	map->minimap.height = win->height / 5;
	map->tab = NULL;
	if (!(calculs->dist = (double *)malloc(sizeof(double) * win->width)))
		return (1);
	player->pos.x = 0;
	player->pos.y = 0;
	player->vel = (t_vector_2d){}; //Inutile
	player->const_vel = 0.05;
	player->dir = 0;
	player->fov = PI / 2;
	calcul_compass(win);
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
			if ((ret = parser(fd, &(win.map), &(win.player))) <= 0)
				return(error(ret, "parser"));
			printf("px = %f, py = %f\n", win.player.pos.x, win.player.pos.y);
			open_window(&win);
			window_loop(&win);
		}
		else if (ft_atoi(av[2]) == 1)
		{
			map_editor(fd);
			printf("map_editor\n");
		}
		quit(&win);
	}
	else
		ft_putendl("usage: ./Wolf3D <map> <0/1>\n0 : Wolf3d\n1 : map_editor");
	return (0);
}
