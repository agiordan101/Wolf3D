/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_drag.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/09 18:49:37 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 19:03:19 by gmonacho    ###    #+. /#+    ###.fr     */
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

int		ed_drag_y_shift(int y, int end, int unit)
{
	static int  first_y = 0;
	int			y_shift;

	y_shift = 0;
	if (!end)

		first_y = y;
	else
		y_shift = (y - first_y) / unit;
	return (y_shift);
}