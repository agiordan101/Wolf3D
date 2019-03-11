/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_zoom.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 21:48:30 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 22:17:30 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ed_zoom(t_map *map, t_dot_2d *pos, int zoom)
{
	map->unit += zoom;
	if (zoom > 0)
	{
		pos->x += (zoom * (map->len_x)) / 2;
		pos->y += (zoom * (map->len_y)) / 2;
	}
	else
	{
		pos->x -= (abs(zoom) * (map->len_x)) / 2;
		pos->y -= (abs(zoom) * (map->len_y)) / 2;
	}
}