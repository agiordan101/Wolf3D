/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_rect.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gal <gal@student.le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 14:00:00 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 02:41:51 by gal         ###    #+. /#+    ###.fr     */
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
		line_put(win , (t_dot_2d){posx, y}, (t_dot_2d){posx, y + height});
		posx++;
	}
}