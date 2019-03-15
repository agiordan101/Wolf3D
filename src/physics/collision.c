/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   collision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 17:45:05 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 15:56:27 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** On va faire simple pour l'instant
*/

static int		test_wall(t_map *map, t_dot_2d dot, t_vector_2d *vector)
{
	int	i;
	int	j;

	j = ft_dtoi_low(dot.x);
	i = ft_dtoi_low(dot.y);
	if (!ft_dec(dot.x))
		j -= vector->x >= 0 ? 0 : 1;
	if (!ft_dec(dot.y))
		i -= vector->y >= 0 ? 0 : 1;
	if (i < 0 || i >= map->len_y || j < 0 || j >= map->len_x)
		*vector = (t_vector_2d){};
	if (map->tab[i][j] != 0 && map->tab[i][j] != PLAYER_TILE
		&& map->tab[i][j] != TRAVERS_TILE)
		return (1);
	return (0);
}

int				collision(t_map *map, t_player *player)
{
	int			ret;
	t_dot_2d	nextx;
	t_dot_2d	nexty;
	t_dot_2d	box;

	box.x = (player->vel.x > 0) ? player->box.x : -player->box.x;
    box.y = (player->vel.y > 0) ? player->box.y : -player->box.y;
	nextx = (t_dot_2d){.x = player->pos.x + player->vel.x + box.x,
						.y = player->pos.y + box.y};
	nexty = (t_dot_2d){.x = player->pos.x + box.x,
						.y = player->pos.y + player->vel.y + box.y};
	if ((ret = test_wall(map, nextx, &(player->vel))) == 1)
		player->vel.x = 0;
	if ((ret = test_wall(map, nexty, &(player->vel))) == 1)
		player->vel.y = 0;
	return (0);
}
