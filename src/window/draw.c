/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 16:24:13 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/04 20:33:26 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

/*static int	get_rgb_surface(SDL_Surface *surface, int x, int y, int elem)
{
	int		bpp;
	Uint8	*pixel;

	bpp = surface->format->BytesPerPixel;
	pixel = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (elem == 1)
		return (((int)pixel >> 24) & 0xFF);
	else if (elem == 2)
		return (((int)pixel >> 16) & 0xFF);
	else if (elem == 3)
		return (((int)pixel >> 8) & 0xFF);
	return ((int)pixel & 0xFF);
} //Completement faux, mais theoriquement vrai.
*/
void		draw(t_win *win, t_calculs *calculs)
{
	t_dot_2d	dfloor1;
	t_dot_2d	dfloor2;
	t_dot_2d	d1;
	t_dot_2d	d2;
	double		h;
	//int			i;
	int			j;
	//double		ySurface;
	//double		pas;
	
	dfloor1.y = win->height;
	dfloor2.y = 0;
	h = 450;
	j = -1;
	while (++j < win->width)
	{
		dfloor1.x = j;
		dfloor2.x = j;
		if (calculs->dist[j] == -1)
		{
			SDL_SetRenderDrawColor(win->rend, BACK_R, BACK_G, BACK_B, 255);
			draw_line(win, dfloor1, dfloor2, win->rend);
		}
		else
		{
			//printf("Dist : %f\n", calculs->dist[i]);
			d1 = (t_dot_2d){.x = j, .y = win->height / 2 - h / calculs->dist[j]};
			d2 = (t_dot_2d){.x = j, .y = win->height / 2 + h / calculs->dist[j]};
			//printf("d1x = %f\td1y = %f\n", d1.x, d1.y);
			SDL_SetRenderDrawColor(win->rend, BACK_R, BACK_G, BACK_B, 255);
			draw_line(win, dfloor2, d1, win->rend);
			
			
			SDL_SetRenderDrawColor(win->rend, WALL_R, WALL_G, WALL_B, 255);
			draw_line(win, d1, d2, win->rend);

			//pseudo code qui sert a choisir le pixel correspondant en Y
			/*pas = win->textures.mur->h / (2 * h / calculs->dist[j]);
			ySurface = 0;
			i = -h / calculs->dist[j];
			while (i < h / calculs->dist[j])
			{
				SDL_SetRenderDrawColor(win->rend, get_rgb_surface(win->textures.mur, j, ySurface, 1),\
													get_rgb_surface(win->textures.mur, j, ySurface, 1),\
													get_rgb_surface(win->textures.mur, j, ySurface, 1),\
													get_rgb_surface(win->textures.mur, j, ySurface, 1));
				SDL_RenderDrawPoint(win->rend, i, j);
				ySurface += pas;
			}*/
			
			SDL_SetRenderDrawColor(win->rend, BACK_R, BACK_G, BACK_B, 255);
			draw_line(win, d2, dfloor1, win->rend);
			
		}
	}
}
