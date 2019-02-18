/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_window.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 18:59:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 18:29:03 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		open_window(t_win *win)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0 || !(win->ptr = SDL_CreateWindow("Wolf3d", 0, 0, win->width, win->height, 0)) || !(win->rend = SDL_CreateRenderer(win->ptr, -1, SDL_RENDERER_SOFTWARE)))
	{
		ft_putstr(SDL_GetError());
		return (0);
	}
	return (1);
}
