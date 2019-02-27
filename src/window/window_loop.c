/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window_loop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 08:56:27 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 20:51:37 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		refresh_window(t_win *win)
{
	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	SDL_RenderClear(win->rend);
	raycasting(win, &(win->map), &(win->player), &(win->calculs));
	draw(win, &(win->calculs));
	SDL_RenderPresent(win->rend);
}

static void keyboard_state(t_win *win, const Uint8 *state)
{
	if (state[SDL_SCANCODE_W])
	{
		win->player.pos.y -= (win->player.pos.y - sin(win->player.dir) * win->player.vel.y < 0) ||\
					(win->player.pos.y - sin(win->player.dir) * win->player.vel.y > win->map.len_y) ?\
					0 : sin(win->player.dir) * win->player.vel.y;
		win->player.pos.x += (win->player.pos.x + cos(win->player.dir) * win->player.vel.x\
							> win->map.len_x[(int)win->player.pos.y]) ||\
							(win->player.pos.x + cos(win->player.dir) * win->player.vel.x < 0) ?\
							0 : cos(win->player.dir) * win->player.vel.x;
	}
	if (state[SDL_SCANCODE_S])
	{
		win->player.pos.y -= (win->player.pos.y - sin(win->player.dir + PI) * win->player.vel.y < 0) ||\
					(win->player.pos.y - sin(win->player.dir + PI) * win->player.vel.y > win->map.len_y) ?\
					0 : sin(win->player.dir + PI) * win->player.vel.y;
		win->player.pos.x += (win->player.pos.x + cos(win->player.dir + PI) * win->player.vel.x\
							> win->map.len_x[(int)win->player.pos.y]) ||\
							(win->player.pos.x + cos(win->player.dir + PI) * win->player.vel.x < 0) ?\
							0 : cos(win->player.dir + PI) * win->player.vel.x;
	}
	if (state[SDL_SCANCODE_A])
	{
		win->player.pos.y -= (win->player.pos.y - sin(win->player.dir + PI / 2) * win->player.vel.y < 0) ||\
					(win->player.pos.y - sin(win->player.dir + PI / 2) * win->player.vel.y > win->map.len_y) ?\
					0 : sin(win->player.dir + PI / 2) * win->player.vel.y;
		win->player.pos.x += win->player.pos.x + cos(win->player.dir + PI / 2) * win->player.vel.x\
							> win->map.len_x[(int)win->player.pos.y] ||\
							(win->player.pos.x + cos(win->player.dir + PI / 2) * win->player.vel.x < 0) ?\
							0 : cos(win->player.dir + PI / 2) * win->player.vel.x;
	}
	if (state[SDL_SCANCODE_D])
	{
		win->player.pos.y -= (win->player.pos.y - sin(win->player.dir - PI / 2) * win->player.vel.y < 0) ||\
					(win->player.pos.y - sin(win->player.dir - PI / 2) * win->player.vel.y > win->map.len_y) ?\
					0 : sin(win->player.dir - PI / 2) * win->player.vel.y;
		win->player.pos.x += win->player.pos.x + cos(win->player.dir - PI / 2) * win->player.vel.x\
							> win->map.len_x[(int)win->player.pos.y] ||\
							(win->player.pos.x + cos(win->player.dir - PI / 2) * win->player.vel.x < 0) ?\
							0 : cos(win->player.dir - PI / 2) * win->player.vel.x;
	}
	if (state[SDL_SCANCODE_RIGHT])
		win->player.dir -= 0.1;
	if (state[SDL_SCANCODE_LEFT])
		win->player.dir += 0.1;
}

static int	keyboard_event(t_win *win, SDL_Event event)
{
	double	dfov;

	dfov = 0.1;
	if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
		return (0);
	if (event.key.keysym.sym == SDLK_KP_MINUS)
		win->player.fov -= win->player.fov - dfov < 0 ? 0 : dfov;
	if (event.key.keysym.sym == SDLK_KP_PLUS)
		win->player.fov += win->player.fov + dfov > 2 * PI ? 0 : dfov;
	return (1);
}

int window_loop(t_win *win)
{
	const Uint8 *state;
	SDL_Event event;
	int loop;

	state = SDL_GetKeyboardState(NULL);
	loop = 1;
	if (!win)
		return (0);
	while (loop)
	{
		SDL_PumpEvents();
		collision(&(win->player), win->map);
		keyboard_state(win, state);
		while (SDL_PollEvent(&event))
		{
			if (!keyboard_event(win, event))
				loop = 0;
		}
		refresh_window(win);
	}
	return (1);
}
