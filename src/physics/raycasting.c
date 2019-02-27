/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 19:27:03 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 18:57:09 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	test_wall	: 1 si mur, 0 sinon
**
**	calcul_dist : Trouve le premier mur pointe par le vector
**
**	raycasting	: Lance des 'calcul_dist' pour chaque pixel de l'ecran avec le
**					vector qui correspond
*/

static int test_wall(t_map *map, t_dot_2d dot, t_vector_2d vector)
{
	int	i;
	int	j;

	j = ft_dtoi_low(dot.x);
	i = ft_dtoi_low(dot.y);
	if (!ft_dec(dot.x))
		j -= vector.x >= 0 ? 0 : 1;
	if (!ft_dec(dot.y)) //Else if
		i -= vector.y >= 0 ? 0 : 1;
	//printf("x = %lf\ty = %lf\n", dot.x, dot.y);
	//printf("i = %i\tj = %i\n", i, j);
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

	//printf("Vector x = %lf\tVector y = %lf\n", vector.x, vector.y);
	next = player->pos;
	nextIndex =	(t_dot_2d){.x = 0, .y = 0};
	calculs->a = vector.y / vector.x;
	calculs->b = vector.origin.y - calculs->a * vector.origin.x;
	//printf("a = %lf\nb = %lf\n", calculs->a, calculs->b);
	while (!test_wall(map, next, vector))
	{
		if (vector.x > 0)
			d1.x = ft_dtoi_up(player->pos.x) + nextIndex.x;
		else
			d1.x = ft_dtoi_low(player->pos.x) + nextIndex.x;
		if (vector.y > 0)
			d2.y = ft_dtoi_up(player->pos.y) + nextIndex.y;
		else
			d2.y = ft_dtoi_low(player->pos.y) + nextIndex.y;
		d1.y = calculs->a * d1.x + calculs->b;
		d2.x = (d2.y - calculs->b) / calculs->a;
		//printf("x1 = %lf\ty1 = %lf\n", d1.x, d1.y);
		//printf("x2 = %lf\ty2 = %lf\n", d2.x, d2.y);
		if (ft__abs(dist_dot_2d(d1, player->pos)) < ft__abs(dist_dot_2d(d2, player->pos)))
		{
			next = d1;
			nextIndex.x += vector.x > 0 ? 1 : -1;
		}
		else
		{
			next = d2;
			nextIndex.y += vector.y > 0 ? 1 : -1;
		}	
	}
	calculs->dist[calculs->i] = dist_dot_2d(next, player->pos);
}

void	raycasting(t_win *win, t_map *map, t_player *player, t_calculs *calculs)
{
	t_vector_2d	vector;
	double		angle;
	double		dangle;

	dangle = player->fov / win->width;
	calculs->i = -1;
	angle = player->fov / 2;
	while (++(calculs->i) < win->width)
	{
		vector = (t_vector_2d){.origin = player->pos,\
								.x = cos(player->dir + angle),
								.y = -sin(player->dir + angle)};
		calcul_dist(map, player, calculs, vector);
		angle -= dangle;
	}
}