/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:26:02 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 17:52:46 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	Differents murs :
**	
**	0	->	Vide
**	1	->	Mur simple
**	2	->	Position initiale du personnage
**	3	->	Mur invisible
**	4	->	Mur traversable
**	5	->	Miroir
*/

static int init(t_win *win, t_map *map, t_calculs *calculs, t_player *player)
{
	map->minimap.x = 10;
	map->minimap.y = 10;
	map->minimap.width = win->height / 4;
	map->minimap.height = win->height / 4;
	map->minimap.static_map = 0;
	map->tab = NULL;
	calculs->angle = -player->fov / 2;
	if (!(calculs->dist = (double *)malloc(sizeof(double) * win->width)))
		return (1);
	if (!(calculs->xray = (double *)malloc(sizeof(double) * win->width)))
		return (1);
	if (!(calculs->orientation = (int *)malloc(sizeof(int) * win->width)))
		return (1);
	if (!(win->textures.tab = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 5)))
		return (1);
	win->textures.tab[4] = NULL;
	if (!(win->textures.tabDev = (SDL_Surface **)malloc(sizeof(SDL_Surface *) * 5)))
		return (1);
	win->textures.tabDev[4] = NULL;
	player->pos.x = 0;
	player->pos.y = 0;
	player->box.x = 0.2;
	player->box.y = 0.2;
	player->vel = (t_vector_2d){}; //Inutile
	player->const_vel = 0.05;
	player->dir = PI / 2;
	player->fov = PI / 2.5;
	win->textures_mode = 1;
	return (0);
} 

int		main(int ac, char **av)
{
	t_win	win;
	int		fd;
	int		ret;

	if (ac > 1)
	{
		if ((fd = params(&win, ac, av)) == -1)
			return (error(-1, "open"));
		if (win.choice == 0)
		{
			if (init(&win, &(win.map), &(win.calculs), &(win.player)))
				return (error(-2, "init"));
			//printf("Fin init\n");
			if ((ret = parser(fd, &(win.map), &(win.player))) <= 0)
				return(error(ret, "parser"));
			//printf("Fin parsing\n");
			if (!open_window(&win))
				return (0);
			//SDL_SetRenderDrawBlendMode(win.rend, SDL_BLENDMODE_BLEND);
			window_loop(&win);
		}
		else if (win.choice == 1) 
			map_editor(fd);
	}
	else
		ft_putendl("usage: ./Wolf3D <map> 0 | 1 [-len <width> <height>]\
					[-name <window's name>]\n0 : Wolf3d\n1 : map_editor");
	quit(&win);
	return (0);
}
