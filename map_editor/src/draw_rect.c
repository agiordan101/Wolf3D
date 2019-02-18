/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_rect.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 14:00:00 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 15:59:20 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "map_editor.h"

void	draw_rect(int x, int y, int width, int height, SDL_Renderer *rend)
{
	int		pix;

	pix = x;
	while (pix < x + width)
	{
		line_put((t_point){x + pix, y}, (t_point){x + pix, y + height}, rend);
		pix++;
	}
}