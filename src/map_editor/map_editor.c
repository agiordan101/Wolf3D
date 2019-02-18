/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_editor.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 09:58:24 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 17:49:30 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init(t_win *win)
{
	win->map.unit = 100;
	win->pos.x = 0;
	win->pos.y = 0;
	win->width = 1200;
	win->height = 800;
}

int				map_editor(int fd)
{
	t_win	win;
	int		error;

	init(&win);
	if (error = parser(fd, &(win.map)) <= 0)
		return (parser_error(error));
	if (!(open_window(&(win.ptr), &(win.rend))))
		return (0);
	window_loop(&win);
	quit(&win);
	return (0);
}