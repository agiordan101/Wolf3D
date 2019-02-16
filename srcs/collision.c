/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   collision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 17:45:05 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 22:58:37 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		collision(t_player *player, t_map map)
{
	double	nx;
	double	ny;
	double	a;
	double	b;
	double	sx;
	double	sy;

	nx = player->pos.x + player->vel.x;
	ny = player->pos.y + player->vel.y;
	a = player->vel.y / player->vel.x;
	b = player->pos.y - a * player->pos.x;
	printf("nx = %f, ny = %f, a = %f, b = %f\n", nx, ny, a, b);
	if (map.tab[get_y((int)ny, map.len_x) + (int)nx] > 0)
	{
		sx = (int)ny / a;
		sy = (int)nx * a;
		printf("s1 = (%f, %d), s2 = (%d, %f)\n", sx, (int)ny, (int)nx, sy);
		/*if (ft__abs(sx - nx) < ft__abs(nx - ft_dtoi_low(nx)))
		{
			player->vel.x = sx;
			player->vel.y = ft_dtoi_low(ny);
			printf("1\n");
		}
		else
		{
			player->vel.x = ft_dtoi_low(nx);
			player->vel.y = sy;
			printf("2\n");
		}
		if (player->pos.x > (int)nx + 1)
		{
			printf("i1\n");
			player->vel.x += 1;
		}
		if (player->pos.y > (int)ny + 1)
		{
			printf("i2\n");
			player->vel.y += 1;
		}*/	
		//printf("vel.x = %f, vel.y = %f\n", player->vel.x, player->vel.y);
		return (1);	
	}
	else
		return (0);
}
