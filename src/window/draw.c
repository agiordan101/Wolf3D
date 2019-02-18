/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 16:24:13 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 19:07:15 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw(t_win *win, t_map *map, t_calculs *calculs)
{
	t_dot_2d	d1;
	t_dot_2d	d2;
	int		i;
	
	i = -1;
	while (++i < map->width)
	{
		d1 = (t_dot_2d){.x = i, .y = 0};
		d2 = (t_dot_2d){.x = i, .y = map->height};
		line_put(d1, d2, win->rend);
		d1 = (t_dot_2d){.x = i, .y = map->height / 2 - map->height / 4 * calculs->dist[i]};
		d2 = (t_dot_2d){.x = i, .y = map->height / 2 + map->height / 4 * calculs->dist[i]};
		line_put(d1, d2, win->rend);
	}
}
