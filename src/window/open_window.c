/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_window.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 18:59:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 21:14:29 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		open_window(t_win *win)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0 || \
	!(win->ptr = SDL_CreateWindow(win->name, 0, 0, win->width, win->height, 0)) || \
	!(win->rend = SDL_CreateRenderer(win->ptr, -1, SDL_RENDERER_SOFTWARE)))
	{
		ft_putstr(ft_strjoin("Open window error : ", SDL_GetError()));
		return (0);
	}
	if (!(win->textures.tab[0] = SDL_LoadBMP("./ressource/monop.bmp")) ||\
		!(win->textures.tab[1] = SDL_LoadBMP("./ressource/red.bmp")) ||\
		!(win->textures.tab[2] = SDL_LoadBMP("./ressource/simple_wall.bmp")) ||\
		!(win->textures.tab[3] = SDL_LoadBMP("./ressource/decorate_wall.bmp")))
	{
		ft_putstr(ft_strjoin("Open texture error : ", SDL_GetError()));
		return (0);
	}
	if (TTF_Init() < 0 || !(win->police = TTF_OpenFont("arial.ttf", 65)))
	{
		ft_putstr(ft_strjoin("Open TTF error : ", TTF_GetError()));
		return (0);
	}
	return (1);
}
