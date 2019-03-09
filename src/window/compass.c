/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compass.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/28 18:53:05 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 15:31:50 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	calcul_compass(t_win *win)
{
	t_dot_2d	d1;
	t_dot_2d	d2;
	t_dot_2d	origin;
	SDL_Rect	rect;
	double		len;

	len = 60;
	SDL_SetRenderDrawColor(win->rend, 0xff, 0x20, 0x20, 255);
	origin = (t_dot_2d){.x = 9 * win->width / 10, .y = win->height / 10};
	d1 = (t_dot_2d){.x = origin.x + cos(PI - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(PI - PI / 2 + win->player.dir) * len};
	d2 = (t_dot_2d){.x = origin.x + cos(0 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(0 - PI / 2 + win->player.dir) * len};
	draw_line(win, d1, d2, win->rend);

	d1 = (t_dot_2d){.x = origin.x + cos(PI / 2 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(PI / 2 - PI / 2 + win->player.dir) * len};
	d2 = (t_dot_2d){.x = origin.x,\
					.y = origin.y};
	draw_line(win, d1, d2, win->rend);

	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	d1 = (t_dot_2d){.x = origin.x,\
					.y = origin.y};
	d2 = (t_dot_2d){.x = origin.x + cos(-PI / 2 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(-PI / 2 - PI / 2 + win->player.dir) * len};
	draw_line(win, d1, d2, win->rend);

	rect = (SDL_Rect){.x = origin.x + cos(PI - PI / 2 + win->player.dir) * 5 * len / 4,\
						.y = origin.y + sin(PI - PI / 2 + win->player.dir) * 5 * len / 4,\
						.w = 100,\
						.h = 100};
	draw_txt(win, ft_strdup("Nfvfvrgbv"), (SDL_Color){255, 255, 255, 255}, rect);
}

/*
void	draw_compass(t_win *win)
{
	SDL_Point	*origin;
	SDL_RendererFlip flip;

	if (!(origin = (SDL_Point *)malloc(sizeof(origin))))
		return ;
	*origin = (SDL_Point){.x = win->width - win->width / 10, .y = win->height / 10};
	flip = SDL_FLIP_NONE;
	d1 = (t_dot_2d){.x = origin.x + cos(PI - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(PI - PI / 2 + win->player.dir) * len};
	d2 = (t_dot_2d){.x = origin.x + cos(0 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(0 - PI / 2 + win->player.dir) * len};
					
	d1 = (t_dot_2d){.x = origin.x + cos(PI / 2 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(PI / 2 - PI / 2 + win->player.dir) * len};
	d2 = (t_dot_2d){.x = origin.x + cos(-PI / 2 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(-PI / 2 - PI / 2 + win->player.dir) * len};
	SDL_RenderCopyEx(win->compass, NULL, NULL, NULL, 0, (const SDL_Point *)origin, flip);
}
*/