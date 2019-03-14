/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_events.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/01 19:31:15 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 16:44:54 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int			mouse_motion(t_win *win, SDL_Event event)
{
	win->mouse.x = event.motion.x;
	win->mouse.y = event.motion.y;
	if (win && event.motion.x)
		return (1);
	return (1);
}

void		ed_keyboard_event(t_win *win)
{
	const Uint8	*state;

	state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_W])
		win->editor.vel.y = -1;
	else if (state[SDL_SCANCODE_S])
		win->editor.vel.y = 1;
	else
		win->editor.vel.y = 0;
	if (state[SDL_SCANCODE_A])
		win->editor.vel.x = -1;
	else if (state[SDL_SCANCODE_D])
		win->editor.vel.x = 1;
	else
		win->editor.vel.x = 0;
}

void		ed_mouse_event(t_win *win)
{
	int		x;
	int		y;

	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		if (ed_is_in_map(x, y, win) && win->editor.drag < 0
									&& win->editor.mouse_ui < 0)
			ed_add_tile(x, y, win, win->editor.selected_tile);
	}
	if (SDL_GetMouseState(&x, &y) & SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
		if (ed_is_in_map(x, y, win) && win->editor.drag < 0
									&& win->editor.mouse_ui < 0)
			ed_add_tile(x, y, win, 0);
	}
}
