/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_resize_y.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 18:28:27 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 19:21:31 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int		**push_back(int **tab, int y_shift, t_len len)
{
	int			**new_tab;
	size_t		i;
	size_t		j;

	if (!(new_tab = (int**)ft_memalloc(sizeof(int*) * (len.y + y_shift))))
		return (NULL);
	i = 0;
	if (tab)
	 	i = 0;
	while (i < len.y + y_shift)
	{
		j = 0;
		if (!(new_tab[i] = (int*)ft_memalloc(sizeof(int) * len.x)))
			return (NULL);
		while (j < len.x)
		{
			if (i < len.y)
				new_tab[i][j] = tab[i][j];
			else
				new_tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (new_tab);
}

static int		**push_front(int **tab, int y_shift, t_len len)
{
	int			**new_tab;
	size_t		i;
	size_t		j;
	size_t		y_limit;

	y_limit = (y_shift >= 0) ? y_shift : abs(y_shift) - 1;
	if (!(new_tab = (int**)ft_memalloc(sizeof(int*) * (len.y + y_shift))))
		return (NULL);
	i = 0;
	while (i < len.y + y_shift)
	{
		j = 0;
		if (!(new_tab[i] = (int*)ft_memalloc(sizeof(int) * len.x)))
			return (NULL);
		while (j < len.x)
		{
			if (i >= (size_t)y_limit)
				new_tab[i][j] = tab[i - y_shift][j];
			else
				new_tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (new_tab);
}

int				**ed_resize_y(int **tab, int y_shift, t_len len, int drag_flag)
{
	int     **new_tab;

	new_tab = NULL;
	if (y_shift != 0)
	{
		if (drag_flag == ED_TDRAG)
		{
			if (!(new_tab = push_front(tab, -y_shift, len)))
				return (NULL);
		}
		else if (drag_flag == ED_BDRAG)
		{
			if (!(new_tab = push_back(tab, y_shift, len)))
				return (NULL);
		}
		return (new_tab);
	}
	else
		return (tab);
}

void		ed_scroll_resize_y(t_dot_2d *pos, int unit, int y_shift, int drag_flag)
{
	if (drag_flag == ED_BDRAG)
		pos->y += y_shift * unit;
}
