/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_update_map_ui.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/14 17:48:40 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 16:34:01 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		protect_map(t_win *win, t_dot_2d *shift)
{
	if (win->editor.drag == ED_RDRAG)
	{
		if (win->map.len_x + shift->x <= 0)
			shift->x = 0;
	}
	else if (win->editor.drag == ED_LDRAG)
	{
		if (win->map.len_x - shift->x <= 0)
			shift->x = 0;
	}
	if (win->editor.drag == ED_BDRAG)
	{
		if (win->map.len_y + shift->y <= 0)
			shift->y = 0;
	}
	else if (win->editor.drag == ED_TDRAG)
	{
		if (win->map.len_y - shift->y <= 0)
			shift->y = 0;
	}
}

int				ed_update_map_ui(t_win *win, t_editor *editor, t_dot_2d shift)
{
	int			**tmp_to_free;

	protect_map(win, &shift);
	tmp_to_free = win->map.tab;
	win->map.tab = ed_resize_x(win->map.tab, shift.x, (t_len){
		win->map.len_x, win->map.len_y}, editor->drag);
	//ft_tabint2del(&tmp_to_free, win->map.len_y);
	ed_scroll_resize_x(&(editor->pos), win->map.unit, shift.x, editor->drag);
	tmp_to_free = win->map.tab;
	win->map.tab = ed_resize_y(win->map.tab, shift.y, (t_len){
		win->map.len_x, win->map.len_y}, editor->drag);
	ed_scroll_resize_y(&(editor->pos), win->map.unit, shift.y, editor->drag);
	//ft_tabint2del(&tmp_to_free, win->map.len_y);
	if (editor->drag == ED_RDRAG)
		win->map.len_x += shift.x;
	else if (editor->drag == ED_LDRAG)
		win->map.len_x -= shift.x;
	if (editor->drag == ED_BDRAG)
		win->map.len_y += shift.y;
	else if (editor->drag == ED_TDRAG)
		win->map.len_y -= shift.y;
	ed_init_map_ui(*win, editor->map_ui, editor->map_ui_color);
	return (1);
}
