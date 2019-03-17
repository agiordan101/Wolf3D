/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:26:02 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 19:48:38 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	Differents murs :
**	
**	0	->	Vide
**	1	->	Mur bois
**	2	->	Mur pierre
**	3	->	Mur pierre taille/ mur traversable
**	4	->	Mur brique
**	5	->	Mur invisible
**	6	->	Position initiale du personnage
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
		return (-2);
	if (!(calculs->xray = (double *)malloc(sizeof(double) * win->width)))
		return (-2);
	if (!(calculs->orientation = (int *)malloc(sizeof(int) * win->width)))
		return (-2);
	player->pos.x = 0;
	player->pos.y = 0;
	player->box.x = 0.2;
	player->box.y = 0.2;
	player->const_vel = VEL;
	player->dir = PI / 2;
	player->fov = PI / 2.5;
	win->textures_mode = 1;
	win->textures.skyrect = (SDL_Rect){0, 0, win->width, win->height / 2};
	return (1);
} 

static int	init_texture(t_win win, SDL_Surface **tab, SDL_Texture **ttab)
{
	size_t	i;

	i = 0;
	while (i < NB_TILES && i < 4)
	{
		if (!(ttab[i] = create_t_from_s(tab[i], win.rend)))
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_win	win;
	int		fd;
	int		ret;

	if (ac > 1)
	{
		if ((fd = params(&win, ac, av)) == -1)
			return (error(-1, "open", &win));
		if (win.choice == 0)
		{
			if (!(ret = init(&win, &(win.map), &(win.calculs), &(win.player))))
				return (error(ret, "init", &win));
			//printf("Fin init\n");
			if ((ret = parser(fd, &(win.map), &(win.player))) <= 0)
				return(error(ret, "parser", &win));
			//printf("Fin parsing\n");
			if (!open_window(&win))
				return (0);
			if (!(ret = init_texture(win, win.textures.tab, win.textures.ttab)))
				return (error(ret, "map_editor : init_texture", &win));
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
