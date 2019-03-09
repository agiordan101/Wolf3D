/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 21:57:42 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 20:20:02 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		ed_init_ui(t_win *win)
{
	int 	unit;
	int		w;
	int		h;

	unit = win->map.unit;
	w = win->width;
	h = win->height;
	win->editor.ui[ED_TDRAG] = ed_new_ui((t_rect){w - w / 10, h / 20, win->width / 15, win->height / 100}, ED_TDRAG);
	win->editor.ui_color[ED_TDRAG] = 0x88888800 + COLOR_OFF;
	return (1);
}

t_ui	ed_new_ui(t_rect rect, int flag)
{
	t_ui	new_ui;

	new_ui.rect = rect;
	new_ui.flag = flag;
	return (new_ui);
}

int		ed_update_ui(t_ui *ui, t_vector_2d velocity)
{
	size_t		i;

	i = 0;
	while (i < NB_UI)
{	
		ui[i].rect.x -= velocity.x;
		ui[i].rect.y -= velocity.y;
		i++;
	}
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
		if ((int)i == flag)
			*pcolor = (*pcolor << 24) | (*pcolor << 16) | (*pcolor << 8) | COLOR_ON;
		else
			*pcolor = (*pcolor << 24) | (*pcolor << 16) | (*pcolor << 8) | COLOR_OFF;
		i++;
	}
}

int		ed_get_ui(t_dot_2d mpos, t_ui *ui)
{
	size_t	i;

	i = 0;
	while (i < NB_UI)
	{
		if (mpos.x >= ui[i].rect.x
				&& mpos.x <= ui[i].rect.x + ui[i].rect.width
				&& mpos.y >= ui[i].rect.y 
				&& mpos.y <= ui[i].rect.y + ui[i].rect.height)
		{
			printf("LOL\n");
			return (ui[i].flag);
		}
		i++;
	}
	printf("NON\n");
	return (-1);
}

/*
t_ui	*ed_add_ui(t_editor *editor, t_ui new_ui)
{
	t_ui	*ui_tab;
	size_t	i;
	
	if (!(ui_tab = (t_ui*)ft_memalloc(sizeof(editor->nb_ui) + 1)))
		return (NULL);
	i = 0;
	while (i < editor->nb_ui)
	{
		ui_tab[i] = editor->ui[i];
		i++;
	}
	ui_tab[i] = new_ui;
	editor->nb_ui++;
	return (ui_tab);
}*/
