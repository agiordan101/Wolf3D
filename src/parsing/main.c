/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:26:02 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 19:06:13 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		init(/*t_win *win, */t_map *map, t_calculs *calculs, t_player *player)
{
	map->tab = NULL;
	map->len_x = NULL;
	win->width = 1200;
	if (!(calculs->dist = (double *)malloc(sizeof(double) * win->width)))
		return (-1);
	player->pos.x = 2.5;
	player->pos.y = 3.5;
	player->vel = (t_vector_2d){.x = 1.0, .y = 0};
	player->dir = PI / 2;
	player->fov = PI / 2;
	return (0);
}

int		main(int ac, char **av)
{
	t_win	win;
	int		fd;
	int		ret;
	int		i;
	int		j;

	if (ac == 2)
	{
		if (init(/*&win, */&(win.map), &(win.calculs), &(win.player)))
		{
			ft_putendl("Error initialisation");
			return (1);
		}
		if ((fd = open(av[1], O_RDONLY)) < 0)  
			return (parser_error(-1));
		ft_putendl("file opened");
		if ((ret = parser(fd, &(win.map))) <= 0)
			return(parser_error(ret));
		ft_putendl("parsing finished");
		i = -1;
		while (++i < 5)
		{
			j = -1;
			while (++j < win.map.len_x[i])
				printf("%i", win.map.tab[i][j]);
			printf("\n");
		}
		raycasting(&(win.map), &(win.player), &(win.calculs));
		i = -1;
		while (++i < win.map.width)
			printf("%lf - ", win.calculs.dist[i]);
		collision(&(win.player), win.map);
		open_window(&(win.ptr));
		window_loop(&win);
		wolf3d_exit(&win);
	}
	else
		ft_putendl("usage: ./Wolf3D <map>\n");
	return (0);
}
