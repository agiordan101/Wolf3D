/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_put.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 18:05:06 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/28 18:46:50 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void			line_put(t_win *win, t_dot_2d p1, t_dot_2d p2, SDL_Renderer *image)
{
	int			i;
	int			n_pixels;
	t_vector_2d	delta;
	double		tmp;
	t_dot_2d	pixel;

	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	if (ft_abs(delta.x) > ft_abs(delta.y))
		tmp = delta.x;
	else
		tmp = delta.y;
	n_pixels = ft_abs(tmp);
	delta.x /= ft_abs(tmp);
	delta.y /= ft_abs(tmp);
	i = -1;
	while (i++ < n_pixels)
	{
		pixel = (t_dot_2d){.x = p1.x + delta.x * i, .y = p1.y + delta.y * i};
		if (pixel.y < win->height && pixel.y >= 0 && pixel.x < win->width && pixel.x >= 0)
			SDL_RenderDrawPoint(image, pixel.x, pixel.y);
	}
}
