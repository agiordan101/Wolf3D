/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window_loop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 08:56:27 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 20:13:36 by agiordan    ###    #+. /#+    ###.fr     */
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
	double	pas;

	pas = 0.1;
	if (state[SDL_SCANCODE_W])
	{
		win->player.pos.y -= (win->player.pos.y - sin(win->player.dir) * pas < 0) ||\
					(win->player.pos.y - sin(win->player.dir) * pas > win->map.len_y) ?\
					0 : sin(win->player.dir) * pas;
		win->player.pos.x += win->player.pos.x + cos(win->player.dir) * pas\
							> win->map.len_x[(int)win->player.pos.y] ?\
							0 : cos(win->player.dir) * pas;
	}
	if (state[SDL_SCANCODE_S])
	{
		win->player.pos.y -= (win->player.pos.y - sin(win->player.dir + PI) * pas < 0) ||\
					(win->player.pos.y - sin(win->player.dir + PI) * pas > win->map.len_y) ?\
					0 : sin(win->player.dir + PI) * pas;
		win->player.pos.x += win->player.pos.x + cos(win->player.dir + PI) * pas\
							> win->map.len_x[(int)win->player.pos.y] ?\
							0 : cos(win->player.dir + PI) * pas;
	}
	if (state[SDL_SCANCODE_A])
	{
		win->player.pos.y -= (win->player.pos.y - sin(win->player.dir + PI / 2) * pas < 0) ||\
					(win->player.pos.y - sin(win->player.dir + PI / 2) * pas > win->map.len_y) ?\
					0 : sin(win->player.dir + PI / 2) * pas;
		win->player.pos.x += win->player.pos.x + cos(win->player.dir + PI / 2) * pas\
							> win->map.len_x[(int)win->player.pos.y] ?\
							0 : cos(win->player.dir + PI / 2) * pas;
	}
	if (state[SDL_SCANCODE_D])
	{
		win->player.pos.y -= (win->player.pos.y - sin(win->player.dir - PI / 2) * pas < 0) ||\
					(win->player.pos.y - sin(win->player.dir - PI / 2) * pas > win->map.len_y) ?\
					0 : sin(win->player.dir - PI / 2) * pas;
		win->player.pos.x += win->player.pos.x + cos(win->player.dir - PI / 2) * pas\
							> win->map.len_x[(int)win->player.pos.y] ?\
							0 : cos(win->player.dir - PI / 2) * pas;
	}
	if (state[SDL_SCANCODE_RIGHT])
		win->player.dir -= 0.1;
	if (state[SDL_SCANCODE_LEFT])
		win->player.dir += 0.1;
}

static int	keyboard_event(t_win *win, SDL_Event event)
{
	if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
		return (0);
	if (event.key.keysym.sym == SDLK_MINUS)
		win->player.fov -= 10;
	if (event.key.keysym.sym == SDLK_PLUS)
		win->player.fov += 10;
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
