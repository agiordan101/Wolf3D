/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 16:24:13 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 19:18:53 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

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
		dfloor1.x = i; //Division 0
		dfloor2.x = i; //Division 0
		//printf("Dist : %f\n", calculs->dist[i]);
		d1 = (t_dot_2d){.x = i, .y = win->height / 2 - 200 / calculs->dist[i]};
		d2 = (t_dot_2d){.x = i, .y = win->height / 2 + 200 / calculs->dist[i]};
		//printf("d1x = %f\td1y = %f\n", d1.x, d1.y);
		SDL_SetRenderDrawColor(win->rend, BACK_R, BACK_G, BACK_B, 255);
		draw_line(win, dfloor2, d1, win->rend);
		if (calculs->dist[i] != -1)
		{
			SDL_SetRenderDrawColor(win->rend, WALL_R, WALL_G, WALL_B, 255);
			draw_line(win, d1, d2, win->rend);
		}
		SDL_SetRenderDrawColor(win->rend, BACK_R, BACK_G, BACK_B, 255);
		draw_line(win, d2, dfloor1, win->rend);
	}
}
