/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_window_loop.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 18:00:19 by gal          #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 21:07:14 by gmonacho    ###    #+. /#+    ###.fr     */
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

static void keyboard_event(t_win *win, const Uint8 *state)
{
	if (state[SDL_SCANCODE_W])
		win->pos.y -= 1;
	else if (state[SDL_SCANCODE_S])
		win->pos.y += 1;
	if (state[SDL_SCANCODE_A])
		win->pos.x -= 1;
	else if (state[SDL_SCANCODE_D])
		win->pos.x += 1;
}

static void mouse_event(t_win *win)
{
	int		x;
	int		y;

	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if (ed_is_in_map(x, y, win))
			ed_add_tile(x, y, win, win->map.tile);
	}
	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
		if (ed_is_in_map(x, y, win))
			ed_add_tile(x, y, win, 0);
	}
}

static int pevent(t_win *win, SDL_Event event)
{
	if (event.type == SDL_QUIT)
		return (0);
	else if (event.type == SDL_KEYDOWN)
	{
		if(event.key.keysym.sym == SDLK_ESCAPE)
			return (0);
		else if(event.key.keysym.sym == SDLK_1)
			win->map.tile = 1;
		else if(event.key.keysym.sym == SDLK_2)
			win->map.tile = 2;
		else if(event.key.keysym.sym == SDLK_RETURN)
				ed_export(win->map);
	}
	else if (event.type == SDL_MOUSEWHEEL)
	{
		if (event.wheel.y > 0)
			win->map.unit += 1;
		else if (event.wheel.y < 0)
			win->map.unit = (win->map.unit > 1) ? win->map.unit - 1 : 1;
	}
	return (1);
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
		keyboard_event(win, state);
		mouse_event(win);
		while (SDL_PollEvent(&event))
			if (!pevent(win, event))
				loop = 0;
		refresh_window(win);
	}
	return (1);
}