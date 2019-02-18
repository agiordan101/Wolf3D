/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   open_window.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/14 18:59:51 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 08:28:59 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		open_window(void **win_ptr)
{
	printf("la\n");
	if (SDL_Init(SDL_INIT_VIDEO) < 0 || !(*win_ptr = SDL_CreateWindow("Wolf3d", 40, 40, 640, 480, SDL_WINDOW_RESIZABLE)))
	{
		ft_putstr(SDL_GetError());
		return (0);
	}
	SDL_Delay(6000);
	printf("la\n");
	SDL_Quit();
	return (1);
}
