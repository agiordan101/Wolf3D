/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_window_loop.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 18:00:19 by gal          #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 20:27:59 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void refresh_window(t_win *win)
{
	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	SDL_RenderClear(win->rend);
	ed_put_map(win);
	ed_put_grid(win);
	SDL_RenderPresent(win->rend);
}

int ed_window_loop(t_win *win)
{
	SDL_Event event;
	int loop;

	loop = 1;
	if (!win)
		return (0);
	while (loop)
	{
		SDL_PumpEvents();
		ed_keyboard_event(win);
		ed_mouse_event(win);
		while (SDL_PollEvent(&event))
			if (!pevent(win, event))
				loop = 0;
		refresh_window(win);
	}
	return (1);
}