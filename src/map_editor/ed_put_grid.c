/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_put_grid.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 15:18:08 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 13:38:11 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int		get_heighter_i(int *tab, int len)
{
	int 	i;
	int		heighter;
	int		index;

	i = 0;
	heighter = 0;
	while (i < len)
	{
		if (tab[i] > heighter)
		{
			heighter = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static int		get_heighter(int *tab, int len)
{
	int 	i;
	int		heighter;

	i = 0;
	heighter = 0;
	while (i < len)
	{
		if (tab[i] > heighter)
			heighter = tab[i];
		i++;
	}
	return (heighter);
}

static void		put_vert(t_win *win)
{
	int		top;
	int		bot;
	int		j;
	int		x;

	top = 0 - win->pos.y;;
	bot = win->map.len_y * win->map.unit - win->pos.y;
	j = 0;
	while (j <= win->map.len_x[get_heighter_i(win->map.len_x, win->map.len_y)])
	{
		x = j * win->map.unit - win->pos.x;
		line_put(win, (t_dot_2d){x, top}, (t_dot_2d){x, bot});
		j++;
	}
}

static void		put_hor(t_win *win)
{
	int		left;
	int		right;
	int		i;
	int		y;

	left = 0 - win->pos.x;
	right = get_heighter(win->map.len_x, win->map.len_y) * win->map.unit - win->pos.x;
	i = 0;
	while (i <= win->map.len_y)
	{
		y = i * win->map.unit - win->pos.y;
		line_put(win, (t_dot_2d){left, y}, (t_dot_2d){right, y});
		i++;
	}
}

void		ed_put_grid(t_win *win)
{
	if (win)
	{
		SDL_SetRenderDrawColor(win->rend, 0xAA, 0xAA, 0xAA, 255);
		put_vert(win);
		put_hor(win);
	}
}