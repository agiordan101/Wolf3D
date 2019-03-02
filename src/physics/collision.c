/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   collision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 17:45:05 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/02 02:13:05 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** On va faire simple poyr l'instant
*/

static int		test_wall(t_map *map, t_dot_2d dot, t_vector_2d vector)
{
	int	i;
	int	j;

	j = ft_dtoi_low(dot.x);
	i = ft_dtoi_low(dot.y);
	if (!ft_dec(dot.x))
		j -= vector.x >= 0 ? 0 : 1;
	if (!ft_dec(dot.y)) //Else if
		i -= vector.y >= 0 ? 0 : 1;
	if (i < 0 || i >= map->len_y || j < 0 || j >= map->len_x)
		return (-1);
	if (map->tab[i][j] == 1)
		return (1);
	return (0);
}

int					collision(t_player *player, t_map *map, t_win *win)
{
	double		bx;
	double		by;
	t_dot_2d	next;
	double		ret;

	win = NULL;
	bx = (player->vel.x >= 0) ? player->box.x : -player->box.x;
	by = (player->vel.y >= 0) ? player->box.y : -player->box.y;
	//printf("x - y = %lf\t%lf\n", player->pos.x, player->pos.y);
	//printf("Dist : %lf\n", calcul_dist_collisions(map, player, &(win->calculs), player->vel));
	next = (t_dot_2d){.x = player->pos.x + player->vel.x,\
						.y = player->pos.y + player->vel.y};
	if ((ret = test_wall(map, next, player->vel)) == 1)
	{
		printf("Collisions\n");
		return (1);
	}
	return (0);
}
