/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_window.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 18:59:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 16:12:35 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "map_editor.h"

int		open_window(SDL_Window **win_ptr, SDL_Renderer **rend)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0 || !(*win_ptr = SDL_CreateWindow("Wolf3d", 0, 0, 1200, 800, 0)) || !(*rend = SDL_CreateRenderer(*win_ptr, -1, SDL_RENDERER_SOFTWARE)))
	{
		ft_putstr(SDL_GetError());
		return (0);
	}
	return (1);
}
