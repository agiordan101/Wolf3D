/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_window.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 18:59:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 20:16:22 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int	load_texture(t_win *win)
{
	SDL_Surface	*tmp;

	if (!(win->textures.tab[0] = SDL_LoadBMP("./ressource/bois.bmp")) ||\
	!(win->textures.tab[1] = SDL_LoadBMP("./ressource/simple_wall.bmp")) ||\
	!(win->textures.tab[2] = SDL_LoadBMP("./ressource/decorate_wall.bmp")) ||\
	!(win->textures.tab[3] = SDL_LoadBMP("./ressource/stone.bmp")) ||\
	!(win->textures.tab[4] = SDL_LoadBMP("./ressource/vitre.bmp")) ||\
	!(win->textures.tab[5] = SDL_LoadBMP("./ressource/superman.bmp")) ||\
	!(tmp = SDL_LoadBMP("./ressource/skyrender0005.bmp")) ||\
	!(win->textures.sky = SDL_CreateTextureFromSurface(win->rend, tmp)) ||\
	!(win->textures.tabDev[0] = SDL_LoadBMP("./ressource/agiordan.bmp")) ||\
	!(win->textures.tabDev[1] = SDL_LoadBMP("./ressource/gmonacho.bmp")) ||\
	!(win->textures.tabDev[2] = SDL_LoadBMP("./ressource/agiordan.bmp")) ||\
	!(win->textures.tabDev[3] = SDL_LoadBMP("./ressource/gmonacho.bmp")) ||\
	!(win->textures.tabDev[4] = SDL_LoadBMP("./ressource/bois.bmp")))
	{
		ft_putstr(ft_strjoin("Open texture error : ", SDL_GetError()));
		return (0);
	}
	SDL_FreeSurface(tmp);
	return (1);
}

int			open_window(t_win *win)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0 || \
	!(win->ptr = SDL_CreateWindow(win->name,
				0, 0, win->width, win->height, 0)) || \
	!(win->rend = SDL_CreateRenderer(win->ptr, -1, SDL_RENDERER_SOFTWARE)))
	{
		ft_putstr(ft_strjoin("Open window error : ", SDL_GetError()));
		return (0);
	}
	if (!(load_texture(win)))
		return (0);
	return (1);
}
