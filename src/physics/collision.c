/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   collision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 17:45:05 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 20:05:03 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** On va faire simple poyr l'instant
*/

int					collision(t_player *player, t_map map)
{
	double		nx;
	double		ny;
	double		bx;
	double		by;

	bx = (player->vel.x >= 0) ? player->box.x : -player->box.x;
	by = (player->vel.y >= 0) ? player->box.y : -player->box.y;
	nx = player->pos.x + player->vel.x + bx;
	ny = player->pos.y + player->vel.y + by;
	if (map.tab[(int)ny][(int)nx] == 1)
	{
		if (map.tab[(int)(player->pos.y)][(int)nx] == 1)
			player->vel.x = 0;
		if (map.tab[(int)ny][(int)(player->pos.x)] == 1)
			player->vel.y = 0;
		return (1);
	}
	return (0);
}
