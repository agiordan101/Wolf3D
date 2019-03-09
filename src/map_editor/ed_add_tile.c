/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_add_tile.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 18:00:25 by gal          #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 17:12:56 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ed_switch_player(int i, int j, t_map *map)
{
	int		ni;
	int		nj;

	ni = 0;
	while (ni < map->len_y)
	{
		nj = 0;
		while (nj < map->len_x)
		{
			if (map->tab[ni][nj] == 2)
				map->tab[ni][nj] = 0;
			nj++;
		}
		ni++;
	}
	map->tab[i][j] = 2;
}

int ed_add_tile(int	x, int y, t_win *win, int tile)
{
	int		i;
	int		j;

	i = ((int)(win->editor.pos.y + y)) / win->map.unit;
	j = ((int)(win->editor.pos.x + x)) / win->map.unit;
	if (win->map.tab[i][j] != tile)
	{
		if (tile == 2)
			ed_switch_player(i, j, &(win->map));
		else
			win->map.tab[i][j] = tile;
		return (1);
	}
	else
		return (0);
}