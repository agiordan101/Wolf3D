/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_ui.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 21:57:42 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 17:45:29 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		ed_init_ui(t_win *win)
{
	size_t	i;
	t_len	s;
	t_ui	*ui;
	Uint32	*ui_color;
	t_rect	tiles_rect;

	s.x = win->width;
	s.y = win->height;
	ui = win->editor.ui;
	ui_color = win->editor.ui_color;
	ui[ED_TILES - 10] = ed_new_ui((t_rect){
		s.x / 20, s.y / 30, s.x - 2 * (s.x / 20), s.y / 15}, ED_TILES);
	ui_color[ED_TILES - 10] = 0x88888800 + COLOR_OFF;
	tiles_rect = ui[ED_TILES - 10].rect;
	i = 0;
	while (i < 8)
	{
		ui[ED_TILE1 - 10 + i] = ed_new_ui((t_rect){
			tiles_rect.x + tiles_rect.height * i,
			tiles_rect.y, tiles_rect.height, tiles_rect.height}, ED_TILE1 + i);
		ui_color[ED_TILE1 - 10 + i] = 0x88888800 + COLOR_OFF;
		i++;
	}
	return (1);
}

t_ui	ed_new_ui(t_rect rect, int flag)
{
	t_ui	new_ui;

	new_ui.rect = rect;
	new_ui.flag = flag;
	return (new_ui);
}

int		ed_update_ui(t_ui *ui)
{
	if (ui)
		return (1);
	return (1);
}

void	ed_update_ui_color(Uint32 *ui_color, int flag)
{
	size_t	i;
	Uint32	*pcolor;

	i = 0;
	while (i < NB_UI)
	{
		pcolor = &ui_color[i];
		if (i != 0)
		{
			if ((int)i == flag - 10)
				*pcolor = (*pcolor << 8) | COLOR_ON;
			else
				*pcolor = (*pcolor << 8) | COLOR_OFF;
		}
		i++;
	}
}

int		ed_get_ui(t_dot_2d mpos, t_ui *ui, int mouse_ui)
{
	int		i;

	i = NB_UI - 1;
	while (i >= 0)
	{
		if (mpos.x >= ui[i].rect.x
				&& mpos.x <= ui[i].rect.x + ui[i].rect.width
				&& mpos.y >= ui[i].rect.y
				&& mpos.y <= ui[i].rect.y + ui[i].rect.height)
			return (ui[i].flag);
		i--;
	}
	return (mouse_ui);
}
