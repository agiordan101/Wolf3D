/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_put.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 18:05:06 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 20:01:04 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

void			line_put(t_win *win, t_dot_2d p1, t_dot_2d p2)
{
	int			i;
	int			nb_point;
	t_vector_2d	delta;

	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	if (ft_abs(delta.x) > ft_abs(delta.y))
	{
		nb_point = ft_abs(delta.x);
		delta.y /= ft_abs(delta.x);
		delta.x /= ft_abs(delta.x);
	}
	else
	{
		nb_point = ft_abs(delta.y);
		delta.x /= ft_abs(delta.y);
		delta.y /= ft_abs(delta.y);
	}
	i = -1;
	while (i++ < nb_point)
	{
		if ((p1.y + delta.y * i) < win->height && (p1.y + delta.y * i) >= 0 && (p1.x + delta.x * i) < win->width && (p1.x + delta.x * i) >= 0)
			SDL_RenderDrawPoint(win->rend, p1.x + delta.x * i, p1.y + delta.y * i);
	}
}
