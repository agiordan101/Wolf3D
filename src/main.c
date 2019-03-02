/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:26:02 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 23:24:40 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int init(t_win *win, t_map *map, t_calculs *calculs, t_player *player)
{
	win->width = 1200;
	win->height = 800;
	map->minimap.x = 10;
	map->minimap.y = 10;
	map->minimap.width = win->width / 5;
	map->minimap.height = win->height / 5;
	map->tab = NULL;
	calculs->angle = -player->fov / 2;
	if (!(calculs->dist = (double *)malloc(sizeof(double) * win->width)))
		return (1);
	player->pos.x = 0;
	player->pos.y = 0;
	player->box.x = 0.2;
	player->box.y = 0.2;
	player->vel = (t_vector_2d){}; //Inutile
	player->const_vel = 0.05;
	player->dir = PI / 2;
	player->fov = PI / 2.5;
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
			open_window(&win);
			calcul_compass(&win);
			window_loop(&win);
		}
		else if (ft_atoi(av[2]) == 1)
			map_editor(fd);
		quit(&win);
	}
	else
		ft_putendl("usage: ./Wolf3D <map> <0/1>\n0 : Wolf3d\n1 : map_editor");
	return (0);
}
