/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 23:34:23 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 17:04:39 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int			error(int error, char *error_source)
{
	ft_putstr("Error (");
	ft_putstr(error_source);
	ft_putstr(") : ");
	if (error == -1)
		return(write(1, "Openning Failed, Please enter a valid file name\n", 48));
	else if (error == -2)
		return(write(1, "Malloc Failed\n", 14));
	else if (error == -3)
		return(write(1, "File must contain only spaces and numbers between 0 and 9\n", 58));
	else if (error == -4)
		return(write(1, "Get_next_line Failed\n", 21));
	else if (error == -5)
		return(write(1, "Invalid Line Size\n", 18));
	else if (error == -6)
		return(write(1, "Player Tile Needed\n", 19));	
	else
		return(write(1, "Undefined\n",  10));
	// Free !
}