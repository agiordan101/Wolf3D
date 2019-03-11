/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_drag.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/09 18:49:37 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 17:25:14 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		ed_drag_x_shift(int x, int end, int unit)
{
	static int  first_x = 0;
	int			x_shift;

	x_shift = 0;
	if (!end)

		first_x = x;
	else
		x_shift = (x - first_x) / unit;
	return (x_shift);
}

t_dot_2d	ed_drag_y_shift(int x, int y, int end, int unit)
{
	static int  first_x;
	static int	first_y;
	t_dot_2d	shift;

	shift.x = 0;
	shift.y = 0;
	if (!end)
	{
		first_x = x;
		first_y = y;
	}
	else
	{
		shift.x = (x - first_x) / unit;
		shift.y = (y - first_y) / unit;
	}
	return (shift);
}