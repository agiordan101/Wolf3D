/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   collision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 17:45:05 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/17 01:54:17 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int		rcoll(t_player *player, double x, double y)
{
	double	nx;
	double	ny;

	nx = player->pos.x + player->vel.x;
	ny = player->pos.y + player->vel.y;
	if (nx > x && ny > y && ny < y + 1)
	{
		player->vel.x = x - player->pos.x;
		return (1);
	}
	else
		return (0);
}


static int		lcoll(t_player *player, double x, double y)
{
	double	nx;
	double	ny;

	nx = player->pos.x + player->vel.x;
	ny = player->pos.y + player->vel.y;
	if (nx < x + 1 && ny > y && ny < y + 1)
	{
		player->vel.x = x - player->pos.x;
		return (1);
	}
	else
		return (0);
}

static int		tcoll(t_player *player, double x, double y)
{
	double	nx;
	double	ny;

	nx = player->pos.x + player->vel.x;
	ny = player->pos.y + player->vel.y;
	if (ny < y + 1 && nx > x && nx < x + 1)
	{
		player->vel.y = y - player->pos.y;
		return (1);
	}
	else
		return (0);
}

static int		bcoll(t_player *player, double x, double y)
{
	double	nx;
	double	ny;

	nx = player->pos.x + player->vel.x;
	ny = player->pos.y + player->vel.y;
	if (ny > y && nx > x && nx < x + 1)
	{
		player->vel.y = y - player->pos.y;
		return (1);
	}
	else
		return (0);
}

int		collision(t_player *player, t_map map)
{
	double		nx;
	double		ny;

	nx = player->pos.x + player->vel.x;
	ny = player->pos.y + player->vel.y;
	if (map.tab[(int)ny][(int)nx])
	{
		if (player->vel.x > 0)
			rcoll(player, (int)nx, (int)ny);
		else if (player->vel.x < 0)
			lcoll(player, (int)nx, (int)ny);
		if (player->vel.y > 0)
			bcoll(player, (int)nx, (int)ny);
		else if (player->vel.y < 0)
			tcoll(player, (int)nx, (int)ny);
		printf("velx = %f, vely = %f\n", player->vel.x, player->vel.y);
		return (1);
	}
	else
		return (0);	
}
