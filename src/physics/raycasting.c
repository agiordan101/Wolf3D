/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 19:27:03 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 15:32:48 by agiordan    ###    #+. /#+    ###.fr     */
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

/*double	prop(double x, t_dot_2d inter1, t_dot_2d inter2)
{
	return ((x - inter1.x) / (inter1.y - inter1.x) * (inter2.y - inter2.x)\
													+ inter2.x);
}*/

static int		test_wall(t_map *map, t_calculs *calculs, t_dot_2d dot, t_vector_2d vector)
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
	if (i < 0 || i >= map->len_y || j < 0 || j >= map->len_x)
		return (-1);
	if (map->tab[i][j] == 1 || map->tab[i][j] == 4)
	{
		if (ft_dec(dot.y)) //Marche normalement
		{
			if (vector.x > 0)
				calculs->xray[calculs->i] = ft_dec(dot.y);
			else
				calculs->xray[calculs->i] = 1 - ft_dec(dot.y);
		}
		else
		{
			if (vector.y > 0)
				calculs->xray[calculs->i] = 1 - ft_dec(dot.x);
			else
				calculs->xray[calculs->i] = ft_dec(dot.x);
		}
		//printf("Xray %i : %lf\n", calculs->i, calculs->xray[calculs->i]);
		return (1);
	}
	return (0);
}

double	calcul_dist(t_map *map, t_player *player, t_calculs *calculs, t_vector_2d vector)
{
	t_dot_2d	next;
	t_dot_2d	nextIndex;
	t_dot_2d	d1;
	t_dot_2d	d2;
	int			ret;

	//printf("Vector x = %lf\tVector y = %lf\n", vector.x, vector.y);
	next = player->pos;
	nextIndex =	(t_dot_2d){.x = 0, .y = 0};
	calculs->a = vector.y /  vector.x; //Division 0
	calculs->b = vector.origin.y - calculs->a * vector.origin.x;
	while ((ret = test_wall(map, calculs, next, vector)) == 0)
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
		d2.x = (d2.y - calculs->b) / calculs->a; //Division 0
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
	return (ret == -1 ? -1 : cos(calculs->angle) * dist_dot_2d(next, player->pos) + 0.00000000001);
}

void			raycasting(t_win *win, t_map *map, t_player *player, t_calculs *calculs)
{
	t_vector_2d	vector;
	double		dangle;

	//printf("Debut raycasting\n");
	dangle = player->fov / win->width;
	calculs->angle = player->fov / 2;
	calculs->i = -1;
	while (++(calculs->i) < win->width)
	{
		vector = (t_vector_2d){.origin = player->pos,\
								.x = cos(player->dir + calculs->angle),
								.y = -sin(player->dir + calculs->angle)};
		calculs->dist[calculs->i] = calcul_dist(map, player, calculs, vector);
		calculs->angle -= dangle;
	}
}