/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_rect.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 14:00:00 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 17:48:05 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

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