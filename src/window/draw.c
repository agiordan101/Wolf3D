/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 16:24:13 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/08 16:18:33 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

//Attention au bpp quand on chope le rgb
static int	get_rgb_surface(SDL_Surface *surface, double x, double y, int elem)
{
	int		bpp;
	Uint32	*pixel;

	bpp = surface->format->BytesPerPixel;
	pixel = surface->pixels + (int)y * surface->pitch + (int)x * bpp;
	if (elem == 1)
		return ((*pixel >> 24) & 0xFF);
	else if (elem == 2)
		return ((*pixel >> 16) & 0xFF);
	else if (elem == 3)
		return ((*pixel >> 8) & 0xFF);
	return (*pixel & 0xFF);
} //Completement faux, mais theoriquement vrai.

void		draw(t_win *win, t_calculs *calculs)
{
	t_dot_2d	dfloor1;
	t_dot_2d	dfloor2;
	t_dot_2d	d1;
	t_dot_2d	d2;
	double		h;
	int			i;
	int			j;
	double		ySurface;
	double		xSurface;
	double		dySurface;
	
	dfloor1.y = win->height;
	dfloor2.y = 0;
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
			h = 450 / calculs->dist[j];
			//printf("Dist : %f\n", calculs->dist[i]);
			d1 = (t_dot_2d){.x = j, .y = win->height / 2 - h};
			d2 = (t_dot_2d){.x = j, .y = win->height / 2 + h};
			//printf("d1x = %f\td1y = %f\n", d1.x, d1.y);
			SDL_SetRenderDrawColor(win->rend, BACK_R, BACK_G, BACK_B, 50);
			draw_line(win, dfloor2, d1, win->rend);
						
			//SDL_SetRenderDrawColor(win->rend, WALL_R, WALL_G, WALL_B, 50);
			//draw_line(win, d1, d2, win->rend);

			dySurface = win->textures.mur->h / (2 * h);
			ySurface = 0;
			xSurface = win->calculs.xray[j] * win->textures.mur->w;
			i = (int)(-h);
			while (++i < (int)h)
			{
				SDL_SetRenderDrawColor(win->rend, get_rgb_surface(win->textures.mur, xSurface, ySurface, 1),\
												get_rgb_surface(win->textures.mur, xSurface, ySurface, 2),\
												get_rgb_surface(win->textures.mur, xSurface, ySurface, 3),\
												get_rgb_surface(win->textures.mur, xSurface, ySurface, 4));
				SDL_RenderDrawPoint(win->rend, j, win->height / 2 + i);
				ySurface += dySurface;
			}
			
			SDL_SetRenderDrawColor(win->rend, BACK_R, BACK_G, BACK_B, 255);
			draw_line(win, d2, dfloor1, win->rend);
			
		}
	}
}
