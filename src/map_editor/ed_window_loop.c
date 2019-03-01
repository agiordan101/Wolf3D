/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_window_loop.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 18:00:19 by gal          #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 19:33:52 by agiordan    ###    #+. /#+    ###.fr     */
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
	const Uint8 *state;
	SDL_Event event;
	int loop;

	state = SDL_GetKeyboardState(NULL);
	loop = 1;
	if (!win)
		return (0);
	while (loop)
	{
		SDL_PumpEvents();
		ed_keyboard_event(win, state);
		ed_mouse_event(win);
		while (SDL_PollEvent(&event))
			if (!pevent(win, event))
				loop = 0;
		refresh_window(win);
	}
	return (1);
}