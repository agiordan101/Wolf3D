/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compass.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 18:53:05 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 20:10:15 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void	calcul_comp(t_win *win, t_dot_2d origin, int len)
{
	t_dot_2d	d1;
	t_dot_2d	d2;

	d1 = (t_dot_2d){.x = origin.x + cos(PI - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(PI - PI / 2 + win->player.dir) * len};
	d2 = (t_dot_2d){.x = origin.x + cos(0 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(0 - PI / 2 + win->player.dir) * len};
	draw_line(win, d1, d2, win->rend);
	d1 = (t_dot_2d){.x = origin.x + cos(PI / 2 - PI / 2 + win->player.dir) *\
																		len,\
					.y = origin.y + sin(PI / 2 - PI / 2 + win->player.dir) *\
																		len};
	d2 = (t_dot_2d){.x = origin.x,\
					.y = origin.y};
	draw_line(win, d1, d2, win->rend);
	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	d1 = (t_dot_2d){.x = origin.x + cos(-PI / 2 - PI / 2 + win->player.dir) *\
																		len,\
					.y = origin.y + sin(-PI / 2 - PI / 2 + win->player.dir) *\
																		len};
	draw_line(win, d1, d2, win->rend);
}

void	print_compass(t_win *win)
{
	SDL_Rect	rect;
	t_dot_2d	origin;
	int			len;

	len = 60;
	SDL_SetRenderDrawColor(win->rend, 0xff, 0x20, 0x20, 255);
	origin = (t_dot_2d){.x = 9 * win->width / 10, .y = win->height / 10};
	calcul_comp(win, origin, len);
	rect = (SDL_Rect){.x = origin.x + cos(PI - PI / 2 + win->player.dir) * 5 * len / 4,\
						.y = origin.y + sin(PI - PI / 2 + win->player.dir) * 5 * len / 4,\
						.w = 100,\
						.h = 100};
}
