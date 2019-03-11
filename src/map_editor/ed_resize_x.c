/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_resize_x.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 16:13:59 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 19:20:39 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int		**push_back(int **tab, int x_shift, t_len len)
{
	int			**new_tab;
	size_t		i;
	size_t		j;

	if (!(new_tab = (int**)ft_memalloc(sizeof(int*) * len.y)))
		return (NULL);
	i = 0;
	if (tab)
	 	i = 0;
	while (i < len.y)
	{
		j = 0;
		if (!(new_tab[i] = (int*)ft_memalloc(sizeof(int) * (len.x + x_shift))))
			return (NULL);
		while (j < len.x + x_shift)
		{
			if (j < len.x)
				new_tab[i][j] = tab[i][j];
			else
				new_tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (new_tab);
}

static int		**push_front(int **tab, int x_shift, t_len len)
{
	int			**new_tab;
	size_t		i;
	size_t		j;
	size_t		x_limit;

	x_limit = (x_shift >= 0) ? x_shift : abs(x_shift) - 1;
	if (!(new_tab = (int**)ft_memalloc(sizeof(int*) * len.y)))
		return (NULL);
	i = 0;
	while (i < len.y)
	{
		j = 0;
		if (!(new_tab[i] = (int*)ft_memalloc(sizeof(int) * (len.x + x_shift))))
			return (NULL);
		while (j < len.x + x_shift)
		{
			if (j >= (size_t)x_limit)
				new_tab[i][j] = tab[i][j - x_shift];
			else
				new_tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (new_tab);
}

int				**ed_resize_x(int **tab, int x_shift, t_len len, int drag_flag)
{
	int     **new_tab;

	new_tab = NULL;
	if (x_shift != 0)
	{
		if (drag_flag == ED_LDRAG)
		{
			if (!(new_tab = push_front(tab, -x_shift, len)))
				return (NULL);
		}
		else if (drag_flag == ED_RDRAG)
		{
			if (!(new_tab = push_back(tab, x_shift, len)))
				return (NULL);
		}
		return (new_tab);
	}
	else
		return (tab);
}

void		ed_scroll_resize_x(t_dot_2d *pos, int unit, int x_shift, int drag_flag)
{
	if (drag_flag == ED_LDRAG)
		pos->x -= x_shift * unit;
}