/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_is_in_map.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 18:31:43 by gal          #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 15:57:55 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		ed_is_in_map(int x, int y, t_win *win)
{
	int 	i;
	int		j;

	i = ((int)(win->editor.pos.y) + y) / win->map.unit;
	j = ((int)(win->editor.pos.x) + x) / win->map.unit;
	if (i >= 0 && i < win->map.len_y &&
		j >= 0 && j < win->map.len_x)
		return (1);
	else
		return (0);
}