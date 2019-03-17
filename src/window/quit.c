/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 09:02:07 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 19:56:41 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		quit(t_win *win)
{
	free(win->calculs.dist);
	free(win->calculs.xray);
	free(win->calculs.orientation);
	ft_tabint2del(&(win->map.tab), win->map.len_y);
	SDL_DestroyWindow(win->ptr);
	SDL_Quit();
	return (1);
}
