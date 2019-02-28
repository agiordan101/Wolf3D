/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compass.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 18:53:05 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/28 19:51:08 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	calcul_compass(t_win *win)
{
	t_dot_2d	d1;
	t_dot_2d	d2;
	t_dot_2d	origin;
	double		len;

	len = 60;
	win->compass = SDL_CreateRenderer(win->ptr, -1, SDL_RENDERER_SOFTWARE);
	SDL_SetRenderDrawColor(win->compass, 0xCC, 0x20, 0x20, 255);
	origin = (t_dot_2d){.x = win->width - win->width / 10, .y = win->height / 10};
	d1 = (t_dot_2d){.x = origin.x - len, .y = origin.y};
	d2 = (t_dot_2d){.x = origin.x + len, .y = origin.y};
	line_put(win, d1, d2, win->compass);
	d1 = (t_dot_2d){.x = origin.x, .y = origin.y - len};
	d2 = (t_dot_2d){.x = origin.x, .y = origin.y + len};
	line_put(win, d1, d2, win->compass);
}

void	draw_compass(t_win *win)
{
	SDL_Point	*origin;
	SDL_RendererFlip flip;

	origin = (SDL_Point *)malloc(sizeof(origin));
	*origin = (SDL_Point){.x = win->width - win->width / 10, .y = win->height / 10};
	flip = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
	/*d1 = (t_dot_2d){.x = origin.x + cos(PI - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(PI - PI / 2 + win->player.dir) * len};
	d2 = (t_dot_2d){.x = origin.x + cos(0 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(0 - PI / 2 + win->player.dir) * len};
					
	d1 = (t_dot_2d){.x = origin.x + cos(PI / 2 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(PI / 2 - PI / 2 + win->player.dir) * len};
	d2 = (t_dot_2d){.x = origin.x + cos(-PI / 2 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(-PI / 2 - PI / 2 + win->player.dir) * len};*/
	SDL_RenderCopyEx(win->compass, NULL, NULL, NULL, 0, (const SDL_Point *)origin, flip);
}
