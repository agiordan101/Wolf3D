/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 19:27:03 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/17 01:37:17 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/wolf3d.h"

static int test_wall(t_map *map, t_dot_2d dot)
{
	int	i;
	int	j;

	j = ft_dtoi_low(dot.x);
	i = ft_dtoi_low(dot.y);
	printf("y = %lf\tx = %lf\n", dot.y, dot.x);
	printf("i = %i\tj = %i\n", i, j);
	if (map->tab[i][j] == 1)
		return (1);
	return (0);
}

static void	calcul_dist(t_map *map, t_player *player, t_calculs *calculs, t_vector_2d vector)
{
	t_dot_2d	next;
	t_dot_2d	nextIndex;
	t_dot_2d	d1;
	t_dot_2d	d2;

	printf("Vector = %lf\tVector = %lf\n", vector.y, vector.x);
	next = player->pos;
	nextIndex =	(t_dot_2d){.x = 0, .y = 0};
	calculs->a = vector.x / vector.y;
	calculs->b = vector.y - calculs->a * vector.x;
	while (!test_wall(map, next))
	{
		if (vector.x > 0)
			d1.x = ft_dtoi_up(vector.x) + nextIndex.x;
		else
			d1.x = ft_dtoi_low(vector.x) + nextIndex.x;
		if (vector.y > 0)
			d2.y = ft_dtoi_up(vector.y) + nextIndex.y;
		else
			d2.y = ft_dtoi_low(vector.y) + nextIndex.y;
		d1.y = calculs->a * d1.x + calculs->b;
		d2.x = (d2.y - calculs->b) / calculs->a;
		printf("y1 = %lf\tx1 = %lf\n", d1.y, d1.x);
		printf("y2 = %lf\tx2 = %lf\n", d2.y, d2.x);
		if (ft__abs(dist_dot_2d(d1, vector.origin)) < ft__abs(dist_dot_2d(d2, vector.origin)))
		{
			next = d1;
			(nextIndex.x)++;
		}
		else
		{
			next = d2;
			(nextIndex.y)++;
		}	
	}
	calculs->dist[calculs->i] = dist_dot_2d(next, vector.origin);
}

void	raycasting(t_map *map, t_player *player, t_calculs *calculs)
{
	t_vector_2d	vector;
	double		angle;
	double		dangle;

	dangle = 2 * player->fov / map->width;
	calculs->i = -1;
	angle = -player->fov;
	while (++(calculs->i) < map->width)
	{
		vector = (t_vector_2d){.origin = player->pos, .x = cos(player->dir + angle),\
											.y = sin(player->dir + angle)};
		calcul_dist(map, player, calculs, vector);
		angle += dangle;
	}
}