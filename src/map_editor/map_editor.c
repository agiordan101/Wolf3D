/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_editor.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 09:58:24 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 19:18:03 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int		init(t_win *win)
{
	win->map.unit = 50;
	win->map.tile = 1;
	win->map.tab = NULL;
	win->editor.pos.x = 0;
	win->editor.pos.y = 0;
	win->editor.vel.x = 0;
	win->editor.vel.y = 0;
	win->name = "map_editor";
	win->width = 1200;
	win->height = 800;
	win->editor.mouse_ui = -1;
	win->editor.drag = 0;
	win->mouse.x = 0;
	win->mouse.y = 0;
	return (1);
}

int				map_editor(int fd)
{
	t_win	win;
	int		ret;

	if (!(ret = init(&win)))
		return (error(ret, "map_editor : init"));
	if ((ret = parser(fd, &(win.map), &(win.player))) <= 0)
		return (error(ret, "map_editor : parser"));
	if (!(ret = ed_init_map_ui(win, win.editor.map_ui, win.editor.map_ui_color)))
		return (error(ret, "map editor : ed_init_map_ui"));
	if (!(open_window(&(win))))
		return (error(-1, "map editor : open_window"));
	
	SDL_SetRenderDrawBlendMode(win.rend, SDL_BLENDMODE_BLEND);
	ed_window_loop(&win);
	quit(&win);
	return (1);
}