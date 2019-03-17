/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   collision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 17:45:05 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 18:19:45 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** On va faire simple pour l'instant
*/

static int		test_wall(t_map *map, t_dot_2d next, t_vector_2d *vel)
{
	int	i;
	int	j;

	j = ft_dtoi_low(next.x);
	i = ft_dtoi_low(next.y);
	if (!ft_dec(next.x))
		j -= vel->x >= 0 ? 0 : 1;
	if (!ft_dec(next.y))
		i -= vel->y >= 0 ? 0 : 1;
	if (i < 0 || i >= map->len_y || j < 0 || j >= map->len_x)
	{
		if (i < 0 || i >= map->len_y)
			*vel = (t_vector_2d){.x = vel->x, .y = 0};
		else
			*vel = (t_vector_2d){.x = 0, .y = vel->y};
	}
	else if (map->tab[i][j] != 0 && map->tab[i][j] != PLAYER_TILE
		&& map->tab[i][j] != TRAVERS_TILE)
		return (1);
	return (0);
}

int				collision(t_map *map, t_player *player)
{
	t_dot_2d	nextx;
	t_dot_2d	nexty;
	t_dot_2d	box;

	box.x = (player->vel.x > 0) ? player->box.x : -player->box.x;
    box.y = (player->vel.y > 0) ? player->box.y : -player->box.y;
	nextx = (t_dot_2d){.x = player->pos.x + player->vel.x + box.x,
						.y = player->pos.y + box.y};
	nexty = (t_dot_2d){.x = player->pos.x + box.x,
						.y = player->pos.y + player->vel.y + box.y};
	if (test_wall(map, nextx, &(player->vel)))
		player->vel.x = 0;
	if (test_wall(map, nexty, &(player->vel)))
		player->vel.y = 0;
	return (0);
}
