/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 19:40:58 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/09 17:53:06 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void    ed_draw_ui(t_win *win, Uint32 *ui_color, t_ui *ui)
{
	int		color;
	int		unit;
	t_rect  rect;
	size_t	i;

	i = 0;
	while (i < NB_UI)
	{
		color = ui_color[i];
		rect = ui[i].rect;
		unit = win->map.unit;
		SDL_SetRenderDrawColor(win->rend, color >> 24, color >> 16, color >> 8, color);
		draw_rect(win, rect);
		i++;
	}
}

void    ed_draw_map_ui(t_win *win, Uint32 *map_ui_color, t_ui *map_ui)
{
	int			color;
	t_dot_2d	wp;
	int			u;
	t_rect  	r;
	size_t		i;

	i = 0;
	while (i < NB_MAP_UI)
	{
		color = map_ui_color[i];
		wp = win->editor.pos;
		r = map_ui[i].rect;
		u = win->map.unit;
		//printf("x = %f, y = %f\n",-wp.x + r.x * u,  -wp.y + r.y * u);
		SDL_SetRenderDrawColor(win->rend, color >> 24, color >> 16, color >> 8, color);
		draw_rect(win, (t_rect){-wp.x + r.x * u, -wp.y + r.y * u, r.width * u, r.height * u});
		i++;
	}
}