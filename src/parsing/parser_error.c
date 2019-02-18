/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser_error.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 23:34:23 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 16:43:49 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int			parser_error(int error)
{
	write(1, "Error : ", 8);
	if (error == -1)
		return(write(1, "Openning Failed, Please enter a valid file name\n", 48));
	else if (error == -2)
		return(write(1, "Malloc Failed\n", 14));
	else if (error == -3)
		return(write(1, "File must contain only spaces and numbers between 0 and 9\n", 58));
	else if (error == -4)
		return(write(1, "Get_next_line Failed\n", 21));
	else
		return(write(1, "Undefined\n",  10));
}