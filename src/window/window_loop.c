/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window_loop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 08:56:27 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 20:32:13 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		move(t_win *win)
{
	win->player.pos.y += win->player.vel.y;
	win->player.pos.x += win->player.vel.x;
}

static void		refresh_window(t_win *win)
{
	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	SDL_RenderClear(win->rend);
	raycasting(win, &(win->player), &(win->calculs));
	draw(win, &(win->calculs), &(win->textures));
	put_minimap(win);
	print_compass(win);
	SDL_RenderPresent(win->rend);
}

int				window_loop(t_win *win)
{
	SDL_Event	event;
	int			loop;

	loop = 1;
	if (!win)
		return (0);
	while (loop)
	{
		SDL_PumpEvents();
		keyboard_state(&(win->player), win);
		if (win->player.vel.x || win->player.vel.y)
			collision(&(win->map), &(win->player));
		move(win);
		while (SDL_PollEvent(&event))
		{
			if (!keyboard_event(win, event))
				loop = 0;
		}
		refresh_window(win);
	}
	return (1);
}
