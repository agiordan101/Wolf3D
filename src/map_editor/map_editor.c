/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_editor.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gal <gal@student.le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 09:58:24 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 20:39:48 by gal         ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init(t_win *win)
{
	win->map.unit = 50;
	win->map.tab = NULL;
	win->pos.x = 0;
	win->pos.y = 0;
	win->width = 1200;
	win->height = 800;
}

int				map_editor(int fd)
{
	t_win	win;
	int		ret;

	init(&win);
	if ((ret = parser(fd, &(win.map))) <= 0)
		return (error(ret, "map_editor : parser"));
	if (!(open_window(&(win))))
		return (0);
	ed_window_loop(&win);
	quit(&win);
	return (0);
}