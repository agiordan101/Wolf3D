/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_put.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 18:05:06 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 18:23:18 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		get_vec(double *dx, double *dy, int *nb_point)
{
	if (ft_abs(*dx) > ft_abs(*dy))
	{
		*nb_point = ft_abs(*dx);
		*dy /= ft_abs(*dx);
		*dx /= ft_abs(*dx);
	}
	else
	{
		*nb_point = ft_abs(*dy);
		*dx /= ft_abs(*dy);
		*dy /= ft_abs(*dy);
	}
}

void			line_put(t_dot_2d p1, t_dot_2d p2, SDL_Renderer *rend)
{
	int			i;
	int			nb_point;
	double		dx;
	double		dy;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	get_vec(&dx, &dy, &nb_point);
	i = -1;
	while (i++ < nb_point)
	{
		//if ((p1.y + dy * i) < WY && (p1.y + dy * i) >= 0 && (p1.x + dx * i) < WX && (p1.x + dx * i) >= 0)
		SDL_RenderDrawPoint(rend, p1.x + dx * i, p1.y + dy * i);
	}
}
