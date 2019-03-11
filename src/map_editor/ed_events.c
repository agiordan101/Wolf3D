/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_events.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/01 19:31:15 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 19:01:33 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int	mouse_motion(t_win *win, SDL_Event event)
{
	/*win->editor.mouse_ui = ed_get_ui((t_dot_2d){event.motion.x,
									event.motion.y},
									win->map.unit,
									win->editor.ui);*/
	win->mouse.x = event.motion.x;
	win->mouse.y = event.motion.y;
	if (win && event.motion.x)
		return (1);
	return (1);
}

int pevent(t_win *win, SDL_Event event)
{
	int		x_shift;
	int		y_shift;

	x_shift = 0;
	y_shift = 0;
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
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (event.button.button == SDL_BUTTON_LEFT
		&& (win->editor.mouse_ui == ED_RDRAG
		|| win->editor.mouse_ui == ED_LDRAG)
		&& win->editor.drag < 0)
		{
			ed_drag_x_shift(event.button.x, 0, win->map.unit);
			win->editor.drag = win->editor.mouse_ui;
		}
		else if (event.button.button == SDL_BUTTON_LEFT
		&& (win->editor.mouse_ui == ED_TDRAG
		|| win->editor.mouse_ui == ED_BDRAG)
		&& win->editor.drag < 0)
		{
			ed_drag_y_shift(event.button.y, 0, win->map.unit);
			win->editor.drag = win->editor.mouse_ui;
		}
	}
	else if (event.type == SDL_MOUSEBUTTONUP)
	{
		if (win->editor.drag >= 0)
		{
			if (win->editor.drag == ED_RDRAG || win->editor.drag == ED_LDRAG)
				x_shift = ed_drag_x_shift(event.button.x, 1, win->map.unit);
			else if (win->editor.drag == ED_TDRAG || win->editor.drag == ED_BDRAG)
				y_shift = ed_drag_y_shift(event.button.y, 1, win->map.unit);
			ed_update_map_ui(win, &(win->editor), (t_dot_2d){x_shift, y_shift});
			win->editor.drag = -1;
		}
	}
	if (event.type == SDL_MOUSEMOTION)
		mouse_motion(win, event);
	return (1);
}

void ed_keyboard_event(t_win *win)
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