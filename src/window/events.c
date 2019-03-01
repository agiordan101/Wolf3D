/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/01 19:25:09 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 19:25:44 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void keyboard_state(t_player *player, const Uint8 *state)
{
	player->vel = (t_vector_2d){.x = 0, .y = 0};
	if (state[SDL_SCANCODE_W])
	{
		player->vel.x += cos(player->dir) * player->const_vel;
		player->vel.y += -sin(player->dir) * player->const_vel;
	}
	if (state[SDL_SCANCODE_S])
	{
		player->vel.x += cos(player->dir + PI) * player->const_vel;
		player->vel.y += -sin(player->dir + PI) * player->const_vel;
	}
	if (state[SDL_SCANCODE_A])
	{
		player->vel.x += cos(player->dir + PI / 2) * player->const_vel;
		player->vel.y += -sin(player->dir + PI / 2) * player->const_vel;
	}
	if (state[SDL_SCANCODE_D])
	{
		player->vel.x += cos(player->dir - PI / 2) * player->const_vel;
		player->vel.y += -sin(player->dir - PI / 2) * player->const_vel;
	}
	if (state[SDL_SCANCODE_RIGHT])
		player->dir -= 0.1;
	if (state[SDL_SCANCODE_LEFT])
		player->dir += 0.1;
}

int	keyboard_event(t_win *win, SDL_Event event)
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