/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window_loop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 08:56:27 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/25 19:08:54 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		refresh_window(t_win *win)
{
	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	SDL_RenderClear(win->rend);
	put_map(win);
	SDL_RenderPresent(win->rend);
}

static void		keyboard_event(t_win *win, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_UP)
		win->player.pos.y -= 10;
	if (event.key.keysym.sym == SDLK_DOWN)
		win->player.pos.y += 10;
	if (event.key.keysym.sym == SDLK_LEFT)
		win->player.pos.x -= 10;
	if (event.key.keysym.sym == SDLK_RIGHT)
		win->player.pos.x += 10;

	if (event.key.keysym.sym == SDLK_x)
		win->player.dir += 0.1;
	if (event.key.keysym.sym == SDLK_c)
		win->player.dir -= 0.1;
	/*if (event.key.keysym.sym == SDLK_'+')
		win->player.fov += 0.1;
	if (event.key.keysym.sym == SDLK_'-')
		win->player.fov -= 0.1;*/
}

int window_loop(t_win *win)
{
	SDL_Event event;
	int exit;

	exit = 0;
	if (!win)
		return (0);
	while (!exit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				exit = 1;
			keyboard_event(win, event);
		}
		refresh_window(win);
	}
	return (1);
}
