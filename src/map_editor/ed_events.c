/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_events.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/01 19:31:15 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 19:35:33 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int pevent(t_win *win, SDL_Event event)
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

void ed_keyboard_event(t_win *win, const Uint8 *state)
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

void ed_mouse_event(t_win *win)
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