/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_window_loop.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 18:00:19 by gal          #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 21:44:55 by gmonacho    ###    #+. /#+    ###.fr     */
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
	//if (win->editor.mouse_ui >= 0)
	ed_update_map_ui_color(win->editor.map_ui_color, win->editor.mouse_ui);
	ed_draw_map_ui(win, win->editor.map_ui_color, win->editor.map_ui);
	ed_draw_ui(win, win->editor.ui_color, win->editor.ui);
	SDL_RenderPresent(win->rend);
}

void ed_move(t_win *win)
{
	win->editor.pos.x += win->editor.vel.x;
	win->editor.pos.y += win->editor.vel.y;
	//ed_update_ui(win->editor.ui, win->editor.vel);
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
		win->editor.mouse_ui = ed_get_map_ui((t_dot_2d){win->mouse.x,
														win->mouse.y},
											win,
											win->editor.map_ui);
		while (SDL_PollEvent(&event))
			if (!pevent(win, event))
				loop = 0;
		ed_move(win);
		refresh_window(win);
	}
	return (1);
}