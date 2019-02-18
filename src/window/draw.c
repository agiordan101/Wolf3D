/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 16:24:13 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 16:24:15 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d"

void	set_pixel(t_win *win, int x, int y, int color)
{
	//Affichage pixel avec la SDL
}

void	ft_put_line(t_win *win, t_dot_2d d1, t_dot_2d d2, int color)
{
	t_vector	pas;
	int			nbpixels;
	int			i;

	pas.x = d2.x - d1.x;
	pas.y = d2.y - d1.y;
	if (ft__abs(pas.x) > ft__abs(pas.y))
	{
		nbpixels = ft__abs(pas.x);
		pas.y /= ft__abs(pas.x);
		pas.x /= ft__abs(pas.x);
	}
	else
	{
		nbpixels = ft__abs(pas.y);
		pas.x /= ft__abs(pas.y);
		pas.y /= ft__abs(pas.y);
	}
	i = -1;
	while (++i < nbpixels)
		set_pixel(win, d1.x + pas.x * i, d1.y + pas.y * i, color);
}

void	draw(t_win *win, t_map *map, t_calculs *calculs)
{
	t_dot_2d	d1;
	t_dot_2d	d2;
	int		i;
	
	i = -1;
	while (++i < map->width)
	{
		d1 = (t_dot_2d){.x = i, .y = 0};
		d2 = (t_dot_2d){.x = i, .y = map->height};
		ft_put_line(d1, d2, BACKGROUND);
		d1 = (t_dot_2d){.x = i, .y = map->height / 2 - map->height / 4 * dist};
		d2 = (t_dot_2d){.x = i, .y = map->height / 2 + map->height / 4 * dist};
		ft_put_line(d1, d2, WALL_COLOR);
	}
}
