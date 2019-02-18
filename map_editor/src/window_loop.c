/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window_loop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 08:56:27 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 16:07:30 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "map_editor.h"

static void		refresh_window(t_win *win)
{
	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	SDL_RenderClear(win->rend);
	put_map(win);
	SDL_RenderPresent(win->rend);
}

static void		keyboard_event(t_win *win, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_w)
		win->pos.y -= 10;
	if (event.key.keysym.sym == SDLK_s)
		win->pos.y += 10;
	if (event.key.keysym.sym == SDLK_a)
		win->pos.x -= 10;
	if (event.key.keysym.sym == SDLK_d)
		win->pos.x += 10;
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