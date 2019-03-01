/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   window_loop.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 08:56:27 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 16:05:27 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		refresh_window(t_win *win)
{
	SDL_SetRenderDrawColor(win->rend, 0, 0, 0, 255);
	SDL_RenderClear(win->rend);
	raycasting(win, &(win->map), &(win->player), &(win->calculs));
	//draw_compass(win);
	draw(win, &(win->calculs));
	put_minimap(win);
	SDL_RenderPresent(win->rend);
	//SDL_RenderPresent(win->compass);
}

static void keyboard_state(t_player *player, const Uint8 *state)
{
	player->vel = (t_vector_2d){.x = 0, .y = 0};
	if (state[SDL_SCANCODE_W])
	{
		player->vel.x += cos(player->dir) * player->const_vel;
		player->vel.y += -sin(player->dir) * player->const_vel;
		/*win->player.pos.y -= (win->player.pos.y - sin(win->player.dir) * win->player.vel.y < 0) ||\
					(win->player.pos.y - sin(win->player.dir) * win->player.vel.y > win->map.len_y) ?\
					0 : sin(win->player.dir) * win->player.vel.y;
		win->player.pos.x += (win->player.pos.x + cos(win->player.dir) * win->player.vel.x\
							> win->map.len_x[(int)win->player.pos.y]) ||\
							(win->player.pos.x + cos(win->player.dir) * win->player.vel.x < 0) ?\
							0 : cos(win->player.dir) * win->player.vel.x;*/
	}
	if (state[SDL_SCANCODE_S])
	{
		player->vel.x += cos(player->dir + PI) * player->const_vel;
		player->vel.y += -sin(player->dir + PI) * player->const_vel;
		/*win->player.pos.y -= (win->player.pos.y - sin(win->player.dir + PI) * win->player.vel.y < 0) ||\
					(win->player.pos.y - sin(win->player.dir + PI) * win->player.vel.y > win->map.len_y) ?\
					0 : sin(win->player.dir + PI) * win->player.vel.y;
		win->player.pos.x += (win->player.pos.x + cos(win->player.dir + PI) * win->player.vel.x\
							> win->map.len_x[(int)win->player.pos.y]) ||\
							(win->player.pos.x + cos(win->player.dir + PI) * win->player.vel.x < 0) ?\
							0 : cos(win->player.dir + PI) * win->player.vel.x;*/
	}
	if (state[SDL_SCANCODE_A])
	{
		player->vel.x += cos(player->dir + PI / 2) * player->const_vel;
		player->vel.y += -sin(player->dir + PI / 2) * player->const_vel;
		/*win->player.pos.y -= (win->player.pos.y - sin(win->player.dir + PI / 2) * win->player.vel.y < 0) ||\
					(win->player.pos.y - sin(win->player.dir + PI / 2) * win->player.vel.y > win->map.len_y) ?\
					0 : sin(win->player.dir + PI / 2) * win->player.vel.y;
		win->player.pos.x += win->player.pos.x + cos(win->player.dir + PI / 2) * win->player.vel.x\
							> win->map.len_x[(int)win->player.pos.y] ||\
							(win->player.pos.x + cos(win->player.dir + PI / 2) * win->player.vel.x < 0) ?\
							0 : cos(win->player.dir + PI / 2) * win->player.vel.x;*/
	}
	if (state[SDL_SCANCODE_D])
	{
		player->vel.x += cos(player->dir - PI / 2) * player->const_vel;
		player->vel.y += -sin(player->dir - PI / 2) * player->const_vel;
		/*win->player.pos.y -= (win->player.pos.y - sin(win->player.dir - PI / 2) * win->player.vel.y < 0) ||\
					(win->player.pos.y - sin(win->player.dir - PI / 2) * win->player.vel.y > win->map.len_y) ?\
					0 : sin(win->player.dir - PI / 2) * win->player.vel.y;
		win->player.pos.x += win->player.pos.x + cos(win->player.dir - PI / 2) * win->player.vel.x\
							> win->map.len_x[(int)win->player.pos.y] ||\
							(win->player.pos.x + cos(win->player.dir - PI / 2) * win->player.vel.x < 0) ?\
							0 : cos(win->player.dir - PI / 2) * win->player.vel.x;*/
	}
	if (state[SDL_SCANCODE_RIGHT])
		player->dir -= 0.1;
	if (state[SDL_SCANCODE_LEFT])
		player->dir += 0.1;
}

static void	move(t_win *win)
{
	if (win->player.pos.x + win->player.vel.x < 0)
		win->player.pos.x = 0.01 + win->player.vel.x;
	else if (win->player.pos.x + win->player.vel.x > win->map.len_x[0] - 1)
		win->player.pos.x = win->map.len_x[0] - 1.01 - win->player.vel.x;
	if (win->player.pos.y + win->player.vel.y < 0)
		win->player.pos.y = 0.01 + win->player.vel.y;
	else if (win->player.pos.y + win->player.vel.y > win->map.len_y - 1)
		win->player.pos.y =  win->map.len_y - 1.01 - win->player.vel.y;
	win->player.pos.y += win->player.vel.y;
	win->player.pos.x += win->player.vel.x;
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
		keyboard_state(&(win->player), state);
		collision(&(win->player), win->map);
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
