/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d_exit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 09:02:07 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 09:09:47 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		wolf3d_exit(t_win *win)
{
	/*
	**	Ne pas oublier Free des differentes structures allouees
	*/
	SDL_DestroyWindow(win->ptr);
	SDL_Quit();
	return (1);
}