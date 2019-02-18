
#include "wolf3d"
# define WALL_COLOR 0x109010
# define BACKGROUND 0x505050

/*
**	0 : > height
**	1.5 * height / dist
*/

void	ft_put_line(t_dot_2d d1, t_dot_2d d2, int color)
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
	int			i;
	
	print_background();
	i = -1;
	while (++i < map->width)
	{
		d1 = (t_dot_2d){.x = i, .y = 0};
		d2 = (t_dot_2d){.x = i, .y = map->height};
		ft_put_line(d1, d2, BACKGROUND);
		d1 = (t_dot_2d){.x = i, .y = map->height / 2 - };
		d2 = (t_dot_2d){.x = i, .y = map->height / 2 + };
		ft_put_line(d1, d2, WALL_COLOR);
	}
}
