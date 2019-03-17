/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window_loop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 08:56:27 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 16:44:58 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		move(t_win *win)
{
	if (win->player.pos.x + win->player.vel.x - win->player.box.x < 0)
		win->player.pos.x = 0 + win->player.vel.x + win->player.box.x;
	else if (win->player.pos.x + win->player.vel.x
			+ win->player.box.x > win->map.len_x - 1)
		win->player.pos.x = win->map.len_x
							- win->player.vel.x - win->player.box.x;
	if (win->player.pos.y + win->player.vel.y - win->player.box.y < 0)
		win->player.pos.y = 0.01 + win->player.vel.y + win->player.box.y;
	else if (win->player.pos.y + win->player.vel.y
			+ win->player.box.y > win->map.len_y - 1)
		win->player.pos.y = win->map.len_y
							- win->player.vel.y - win->player.box.y;
	win->player.pos.y += win->player.vel.y;
	win->player.pos.x += win->player.vel.x;
}

void			refresh_window(t_win *win)
{
	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	SDL_RenderClear(win->rend);
	raycasting(win, &(win->player), &(win->calculs));
	draw(win, &(win->calculs), &(win->textures));
	put_minimap(win);
	calcul_compass(win);
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
	}
	return (1);
}
