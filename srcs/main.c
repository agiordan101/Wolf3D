/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:26:02 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:45:37 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/wolf3d.h"

int		parser_error(int error)
{
	write(1, "Error : ", 8);
	if (error == -1)
		return(write(1, "Openning Failed\n", 15));
	else if (error == -2)
		return(write(1, "Malloc Failed\n", 14));
	else if (error == -3)
		return(write(1, "File must contain only spaces and numbers between 0 and 9\n", 58));
	else if (error == -4)
		return(write(1, "Get_next_line Failed\n", 21));
	else
		return(write(1, "Undefined\n",  10));
}

int		main(int ac, char **av)
{
	t_map	map;
	int		fd;
	int		ret;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)  
			return (parser_error(-1));
		if ((ret = parser(fd, &map)) <= 0)
			return(parser_error(ret));
		ft_intput(map.tab, 100);
	}
	else
		write(1, "./wolf3d map\n", 13);
	return (0);
}
