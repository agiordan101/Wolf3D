/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 09:02:07 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 17:07:57 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		quit(t_win *win)
{
	/*
	**	Ne pas oublier Free des differentes structures allouees
	*/
	SDL_DestroyWindow(win->ptr);
	SDL_Quit();
	return (1);
}