/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window_loop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 08:56:27 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 19:53:56 by agiordan    ###    #+. /#+    ###.fr     */
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
	/*if (state[SDL_SCANCODE_W])
		win->player.pos.y -= win->player.pos.y - pas <= 0 ? 0 : pas;
	if (state[SDL_SCANCODE_S])
		win->player.pos.y += win->player.pos.y + pas > win->map.len_y ? 0 : pas;
	if (state[SDL_SCANCODE_A])
		win->player.pos.x -= win->player.pos.x - pas <= 0 ? 0 : pas;
	if (state[SDL_SCANCODE_D])
		win->player.pos.x += win->player.pos.x + pas > win->map.len_x[(int)win->player.pos.y] ? 0 : pas;*/
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
	{
		printf("RIGHT\n");
		win->player.dir -= 0.1;
	}
	if (state[SDL_SCANCODE_LEFT])
	{
		printf("LEFT\n");
		win->player.dir += 0.1;
	}
}

static void		keyboard_event(t_win *win, SDL_Event event)
{
	if (event.key.keysym.sym == SDLK_x)
		win->player.dir += 0.1;
	if (event.key.keysym.sym == SDLK_c)
		win->player.dir -= 0.1;
	/*if (event.key.keysym.sym == SDLK_'+')
		win->player.fov += 0.1;
	if (event.key.keysym.sym == SDLK_'-')
		win->player.fov -= 0.1;*/
}

int window_loop(t_win *win)
{
	const Uint8 *state;
	SDL_Event event;
	int exit;

	state = SDL_GetKeyboardState(NULL);
	exit = 0;
	if (!win)
		return (0);
	while (!exit)
	{
		SDL_PumpEvents();
		keyboard_state(win, state);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				exit = 1;
			keyboard_event(win, event);
		}
		refresh_window(win);
	}
	return (1);
}
