/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 19:40:58 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 19:38:17 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void			ed_draw_ui(t_win *win,
							Uint32 *ui_color, t_ui *ui,
							SDL_Texture **texture)
{
	int			color;
	SDL_Rect	rect;
	size_t		i;

	i = 0;
	if (texture)
	{
		while (i < NB_UI && i < N_SURFACE + 1)
		{
			color = ui_color[i + 1];
			rect = (SDL_Rect){ui[i + 1].rect.x, ui[i + 1].rect.y,
							ui[i + 1].rect.width, ui[i + 1].rect.height};
			SDL_RenderCopy(win->rend, texture[i], NULL, &rect);
			draw_rect(win, ui[i].rect);
			i++;
		}
	}
}

void			ed_draw_map_ui(t_win *win,
								Uint32 *map_ui_color,
								t_ui *map_ui)
{
	int			color;
	t_dot_2d	wp;
	int			u;
	t_rect		r;
	size_t		i;

	i = 0;
	while (i < NB_MAP_UI)
	{
		color = map_ui_color[i];
		wp = win->editor.pos;
		r = map_ui[i].rect;
		u = win->map.unit;
		SDL_SetRenderDrawColor(win->rend, color >> 24, color >> 16,
								color >> 8, color);
		draw_rect(win, (t_rect){-wp.x + r.x * u,
								-wp.y + r.y * u,
								r.width * u, r.height * u});
		i++;
	}
}
