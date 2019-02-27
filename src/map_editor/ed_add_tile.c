/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_add_tile.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gal <gal@student.le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 18:00:25 by gal          #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 02:52:30 by gal         ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int ed_add_tile(int	x, int y, t_win *win, int tile)
{
	int		i;
	int		j;

	i = ((int)(win->pos.y + y)) / win->map.unit;
	j = ((int)(win->pos.x + x)) / win->map.unit;
	if (win->map.tab[i][j] != tile)
	{
		win->map.tab[i][j] = tile;
		return (1);
	}
	else
		return (0);
}