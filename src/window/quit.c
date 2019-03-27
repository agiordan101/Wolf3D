/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   quit.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 09:02:07 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 19:57:30 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		quit(t_win *win)
{
	int	i;

	free(win->calculs.dist);
	free(win->calculs.xray);
	free(win->calculs.orientation);
	ft_tabint2del(&(win->map.tab), win->map.len_y);
	i = -1;
	while (++i < N_SURFACE)
	{
		SDL_FreeSurface(win->textures.tab[i]);
		SDL_FreeSurface(win->textures.tabdev[i]);
	}
	i = -1;
	while (++i < NB_TILES)
		SDL_DestroyTexture(win->textures.ttab[i]);
	SDL_DestroyTexture(win->textures.sky);
	SDL_DestroyWindow(win->ptr);
	SDL_DestroyRenderer(win->rend);
	SDL_Quit();
	return (1);
}
