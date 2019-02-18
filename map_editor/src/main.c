/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 09:58:24 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 15:09:47 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "map_editor.h"

static void		init(t_win *win)
{
	win->map.unit = 100;
	win->pos.x = 0;
	win->pos.y = 0;
	win->width = 1200;
	win->height = 800;
}

int				main(int ac, char **av)
{
	t_win	win;
	int 	fd;

	init(&win);
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0 || (fd = parser(fd, &(win.map)) <= 0))
			return (parser_error(fd));
		if (!(open_window(&(win.ptr), &(win.rend))))
			return (0);
		window_loop(&win);
		quit(&win);
	}
	else
	{
		printf("2\n");
	}
	return (0);
}