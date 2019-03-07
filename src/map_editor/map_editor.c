/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_editor.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 09:58:24 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 22:31:56 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init(t_win *win)
{
	win->map.unit = 50;
	win->map.tile = 1;
	win->map.tab = NULL;
	win->pos.x = 0;
	win->pos.y = 0;
	win->name = "map_editor";
	win->width = 1200;
	win->height = 800;
	win->editor.frame_color[0] = 0xAAAAAA;
	win->editor.frame_color[1] = 0xAAAAAA;
	win->editor.frame_color[2] = 0xAAAAAA;
	win->editor.frame_color[3] = 0xAAAAAA;
	win->editor.mouse_ui = NULL;
	win->editor.dragging = NULL;
}

int				map_editor(int fd)
{
	t_win	win;
	int		ret;

	init(&win);
	if ((ret = parser(fd, &(win.map), &(win.player))) <= 0)
		return (error(ret, "map_editor : parser"));
	if (!(open_window(&(win))))
		return (error(-1, "map editor : open_window"));
	ed_window_loop(&win);
	quit(&win);
	return (1);
}