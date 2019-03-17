/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_pevent.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 15:14:52 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 15:58:47 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		mouse_button_down(t_win *win, SDL_Event event)
{
	if (event.button.button == SDL_BUTTON_LEFT)
	{
		if ((win->editor.mouse_ui == ED_RDRAG
		|| win->editor.mouse_ui == ED_LDRAG)
		&& win->editor.drag < 0)
		{
			ed_drag_x_shift(event.button.x, 0, win->map.unit);
			win->editor.drag = win->editor.mouse_ui;
		}
		else if ((win->editor.mouse_ui == ED_TDRAG
		|| win->editor.mouse_ui == ED_BDRAG)
		&& win->editor.drag < 0)
		{
			ed_drag_y_shift(event.button.y, 0, win->map.unit);
			win->editor.drag = win->editor.mouse_ui;
		}
		if (win->editor.mouse_ui >= 11
		&& win->editor.mouse_ui <= 10 + NB_UI)
			win->editor.selected_tile = win->editor.mouse_ui - 10;
	}
}

static void		mouse_button_up(t_win *win, SDL_Event event)
{
	t_dot_2d		shift;

	shift.x = 0;
	shift.y = 0;
	if (win->editor.drag >= 0)
	{
		if (win->editor.drag == ED_RDRAG || win->editor.drag == ED_LDRAG)
			shift.x = ed_drag_x_shift(event.button.x, 1, win->map.unit);
		else if (win->editor.drag == ED_TDRAG || win->editor.drag == ED_BDRAG)
			shift.y = ed_drag_y_shift(event.button.y, 1, win->map.unit);
		ed_update_map_ui(win, &(win->editor), shift);
		win->editor.drag = -1;
	}
}

static int		keydown(t_win *win, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_ESCAPE)
		return (0);
	else if (event.key.keysym.sym == SDLK_1)
		win->map.tile = 1;
	else if (event.key.keysym.sym == SDLK_2)
		win->map.tile = 2;
	else if (event.key.keysym.sym == SDLK_RETURN)
		ed_export(win->map);
	return (1);
}

int				pevent(t_win *win, SDL_Event event)
{
	if (event.type == SDL_QUIT)
		return (0);
	else if (event.type == SDL_KEYDOWN)
	{
		if (!keydown(win, event))
			return (0);
	}
	else if (event.type == SDL_MOUSEWHEEL)
	{
		if (event.wheel.y > 0)
			ed_zoom(&(win->map), &(win->editor.pos), 1);
		else if (event.wheel.y < 0)
			ed_zoom(&(win->map), &(win->editor.pos), -1);
	}
	if (event.type == SDL_MOUSEBUTTONDOWN)
		mouse_button_down(win, event);
	else if (event.type == SDL_MOUSEBUTTONUP)
		mouse_button_up(win, event);
	if (event.type == SDL_MOUSEMOTION)
		mouse_motion(win, event);
	return (1);
}
