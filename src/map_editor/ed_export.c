/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ed_export.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/27 13:42:55 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 15:11:01 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int		open_new_fd(char *filename)
{
	int	fd;
 
	if (!(fd = open(filename, O_CREAT | O_WRONLY | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)))
		return (-1);
	return (fd);
}

int			ed_export(t_map map)
{
	int     i;
	int     j;
	int		fd_export;

	fd_export = open_new_fd("new_map.w3d");
	i = 0;
	while (i < map.len_y)
	{
		j = 0;
		while (j < map.len_x[i])
		{
			write(fd_export, ft_strjoin(ft_itoa(map.tab[i][j]), " "), 2);
			j++;
		}
		write(fd_export, "\n", 1);
		i++;
	}
	return (1);
}