/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 16:24:13 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 22:18:40 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_compass(t_win *win)
{
	t_dot_2d	d1;
	t_dot_2d	d2;
	t_dot_2d	origin;
	double		len;

	len = 60;
	SDL_SetRenderDrawColor(win->rend, 0xCC, 0x20, 0x20, 255);
	origin = (t_dot_2d){.x = win->width - win->width / 10, .y = win->height / 10};
	d1 = (t_dot_2d){.x = origin.x + cos(PI - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(PI - PI / 2 + win->player.dir) * len};
	d2 = (t_dot_2d){.x = origin.x + cos(0 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(0 - PI / 2 + win->player.dir) * len};
	line_put(win, d1, d2);
	d1 = (t_dot_2d){.x = origin.x + cos(PI / 2 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(PI / 2 - PI / 2 + win->player.dir) * len};
	d2 = (t_dot_2d){.x = origin.x + cos(-PI / 2 - PI / 2 + win->player.dir) * len,\
					.y = origin.y + sin(-PI / 2 - PI / 2 + win->player.dir) * len};
	line_put(win, d1, d2);
}

void		draw(t_win *win, t_calculs *calculs)
{
	t_dot_2d	dfloor1;
	t_dot_2d	dfloor2;
	t_dot_2d	d1;
	t_dot_2d	d2;
	int		i;
	
	//printf("\n\n\n\n");
	dfloor1.y = win->height;
	dfloor2.y = 0;
	i = -1;
	while (++i < win->width)
	{
		dfloor1.x = i;
		dfloor2.x = i;
		//printf("Dist : %f\n", calculs->dist[i]);
		d1 = (t_dot_2d){.x = i, .y = win->height / 2 - 100 / calculs->dist[i]};
		d2 = (t_dot_2d){.x = i, .y = win->height / 2 + 100 / calculs->dist[i]};
		//printf("d1x = %f\td1y = %f\n", d1.x, d1.y);
		SDL_SetRenderDrawColor(win->rend, BACK_R, BACK_G, BACK_B, 255);
		line_put(win, dfloor2, d1);
		SDL_SetRenderDrawColor(win->rend, WALL_R, WALL_G, WALL_B, 255);
		line_put(win, d1, d2);
		SDL_SetRenderDrawColor(win->rend, BACK_R, BACK_G, BACK_B, 255);
		line_put(win, d2, dfloor1);
	}
	draw_compass(win);
}
