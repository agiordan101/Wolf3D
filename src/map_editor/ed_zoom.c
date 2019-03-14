/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_zoom.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 21:48:30 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/14 18:12:41 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	ed_zoom(t_map *map, t_dot_2d *pos, int zoom)
{
	int		nzoom;

	nzoom = 0;
	if (zoom > 0)
		nzoom = map->unit / 10;
	else if (zoom < 0)
		nzoom = -map->unit / 10;
	if (nzoom == 0)
		nzoom = zoom;
	map->unit += nzoom;
	if (map->unit <= 1)
		map->unit = 2;
	else
	{
		if (zoom > 0)
		{
			pos->x += (nzoom * (map->len_x)) / 2;
			pos->y += (nzoom * (map->len_y)) / 2;
		}
		else
		{
			pos->x -= (abs(nzoom) * (map->len_x)) / 2;
			pos->y -= (abs(nzoom) * (map->len_y)) / 2;
		}
	}
}
