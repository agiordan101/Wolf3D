/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   collision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gal <gal@student.le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 17:45:05 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/28 02:08:54 by gal         ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int		get_smaller(t_player player, t_dot_2d sx, t_dot_2d sy)
{
	if (sqrt((sx.x - player.pos.x) * (sx.x - player.pos.x) +
			 (sx.y - player.pos.y) * (sx.y - player.pos.y)) <=
		sqrt((sy.x - player.pos.x) * (sy.x - player.pos.x) +
			 (sy.y - player.pos.y) * (sy.y - player.pos.y)))
		return (0);
	else
		return (1);
}

static void		set_vel(t_player *player, double nx, double ny)
{
	double		a;
	int			x_shift;
	int			y_shift;
	double		sx;
	double		sy;

	x_shift = (cos(player->dir) >= 0) ? 0 : 1;
	y_shift = (-sin(player->dir) >= 0) ? 0 : 1;
	a = (ny - player->pos.y) / (nx - player->pos.x);
	sx = (((int)ny + y_shift) + player->pos.x) / a;
	sy = a * ((int)nx + x_shift) + player->pos.x;
	if (get_smaller(*player, (t_dot_2d){sx, (int)ny + y_shift},
							(t_dot_2d){(int)nx + x_shift, sy}))
	{
		printf("1\n");
		player->vel.x = sx - player->pos.x;
		player->vel.y = (int)ny + y_shift - player->pos.y;
	}
	else
	{
		printf("2\n");
		player->vel.x = (int)nx + x_shift - player->pos.x;
		player->vel.y = sy - player->pos.y;
	}
	printf("x = %f, y = %f\n", player->pos.x + player->vel.x, player->pos.y + player->vel.y);
}

int					collision(t_player *player, t_map map)
{
	double		nx;
	double		ny;

	nx = player->pos.x + player->vel.x;
	ny = player->pos.y + player->vel.y;
	if (map.tab[(int)ny][(int)nx] == 1)
	{
		printf("velx = %f, vely = %f\n", player->vel.x, player->vel.y);
		set_vel(player, nx, ny);
		printf("nvelx = %f, nvely = %f\n", player->vel.x, player->vel.y);
		return (1);
	}
	return (0);
}
