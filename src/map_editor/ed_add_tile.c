/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_add_tile.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gal <gal@student.le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 18:00:25 by gal          #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 19:39:01 by gal         ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int ed_add_tile(int	x, int y, t_win *win)
{
	int		i;
	int		j;

	i = (win->pos.y - y) / win->map.unit;
	j = (win->pos.x - x) / win->map.unit;
	if (win->map.tab[i][j] == 0)
	{
		win->map.tab[i][j] = 1;
		return (1);
	}
	else
		return (0);
}