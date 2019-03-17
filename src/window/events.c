/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/01 19:25:09 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 19:35:22 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		keyboard_move(const Uint8 *state, t_player *player)
{
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
		player->dir -= 0.07;
	if (state[SDL_SCANCODE_LEFT])
		player->dir += 0.07;
}

static void		keyboard_norme(const Uint8 *state, t_win *win)
{
	if (state[SDL_SCANCODE_TAB])
	{
		win->map.minimap.x_unit = (win->map.len_x > win->map.len_y) ?
			(win->width - 10) / win->map.len_x :
			(win->height - 10) / win->map.len_y;
		win->map.minimap.y_unit = (win->map.len_x > win->map.len_y) ?
			(win->width - 10) / win->map.len_x :
			(win->height - 10) / win->map.len_y;
		win->map.minimap.height = win->map.len_y
			* win->map.minimap.y_unit;
		win->map.minimap.width = win->map.len_x
			* win->map.minimap.x_unit;
		win->map.minimap.static_map = 1;
	}
	else
	{
		win->map.minimap.height = win->height / 4;
		win->map.minimap.width = win->height / 4;
		win->map.minimap.x = 10;
		win->map.minimap.x_unit = win->map.minimap.width / 4;
		win->map.minimap.y_unit = win->map.minimap.width / 4;
		win->map.minimap.static_map = 0;
	}
}

void			keyboard_state(t_player *player, t_win *win)
{
	const Uint8	*state;

	state = SDL_GetKeyboardState(NULL);
	player->vel = (t_vector_2d){.x = 0, .y = 0};
	keyboard_move(state, player);
	keyboard_norme(state, win);
}

int				keyboard_event(t_win *win, SDL_Event event)
{
	double		dfov;

	dfov = 0.1;
	if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
		return (0);
	else if (event.key.keysym.sym == SDLK_KP_MINUS)
		win->player.fov -= win->player.fov - dfov < 0 ? 0 : dfov;
	else if (event.key.keysym.sym == SDLK_KP_PLUS)
		win->player.fov += win->player.fov + dfov > 2 * PI ? 0 : dfov;
	else if (event.key.keysym.sym == SDLK_1)
		win->textures_mode = 1;
	else if (event.key.keysym.sym == SDLK_2)
		win->textures_mode = 2;
	else if (event.key.keysym.sym == SDLK_3)
		win->textures_mode = 3;
	return (1);
}
