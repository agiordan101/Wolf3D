/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 09:02:07 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 16:41:26 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		quit(t_win *win)
{
	SDL_DestroyWindow(win->ptr);
	TTF_CloseFont(win->police);
	TTF_Quit();
	SDL_Quit();
	return (1);
}
