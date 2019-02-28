/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_rect.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 14:00:00 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/28 19:13:32 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_rect(t_win *win, int x, int y, int width, int height)
{
	int		posx;

	posx = x;
	while (posx < x + width)
	{
		line_put(win , (t_dot_2d){posx, y}, (t_dot_2d){posx, y + height}, win->rend);
		posx++;
	}
}