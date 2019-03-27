/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flags.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/05 15:06:12 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 21:04:42 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static void		flags(t_win *win, int ac, char **av, int *i)
{
	int	fd;

	if ((fd = open(av[*i], O_RDONLY)) > 0)
		win->fd = fd;
	else if (!ft_strcmp(av[*i], "-name"))
	{
		if (*i + 1 < ac)
			win->name = av[++(*i)];
	}
	else if (!ft_strcmp(av[*i], "-len"))
	{
		if (*i + 1 < ac)
			win->width = ft_atoi(av[++(*i)]);
		if (*i + 1 < ac)
			win->height = ft_atoi(av[++(*i)]);
	}
	else if (!ft_strcmp(av[*i], "-direction"))
	{
		if (*i + 1 < ac)
			win->player.dir = ft_atoi(av[++(*i)]);
	}
	else if (ft_atoi(av[*i]) >= 0 && ft_atoi(av[*i]) <= 1)
		win->choice = ft_atoi(av[(*i)]);
}

int				params(t_win *win, int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr("usage: ./Wolf3D <map> 0 | 1 [-len <width> <height>]");
		ft_putendl("[-name <window's name>]\n0 : Wolf3d\n1 : map_editor");
		return (-1);
	}
	win->name = "Wolf3D";
	win->width = 1500;
	win->height = 1000;
	win->choice = -1;
	win->fd = -1;
	while (++i < ac)
		flags(win, ac, av, &i);
	return (win->fd);
}
