/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 16:24:13 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/12 21:37:40 by agiordan    ###    #+. /#+    ###.fr     */
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
}

static void		draw_sky(t_win *win, t_textures *textures, int j)
{
	double		ySurface;
	double		xSurface;
	double		dySurface;
	int			i;

	ySurface = 0;
	xSurface = ((double)j / win->width) * textures->sky->w;
	dySurface = (double)textures->sky->h / win->height;
	i = 0;
	while (++i < win->height / 2)
	{
		SDL_SetRenderDrawColor(win->rend, get_rgb_surface(textures->sky, xSurface, ySurface, 2),\
										get_rgb_surface(textures->sky, xSurface, ySurface, 3),\
										get_rgb_surface(textures->sky, xSurface, ySurface, 1),\
										get_rgb_surface(textures->sky, xSurface, ySurface, 4));
		SDL_RenderDrawPoint(win->rend, j, i);
		ySurface += dySurface;
	}
}

static void		draw_wall(t_win *win, t_calculs *calculs, t_textures *textures, int j)
{
	double		ySurface;
	double		xSurface;
	double		dySurface;
	double		h;
	int			i;

	h = HEIGHT_WALL / calculs->dist[j];
	textures->current = textures->tab[calculs->orientation[j] - 1];
	ySurface = 0;
	xSurface = win->calculs.xray[j] * textures->current->w;
	dySurface = textures->current->h / (2 * h);
	i = (int)(-h);
	while (++i < (int)h)
	{
		SDL_SetRenderDrawColor(win->rend, get_rgb_surface(textures->current, xSurface, ySurface, 2),\
										get_rgb_surface(textures->current, xSurface, ySurface, 3),\
										get_rgb_surface(textures->current, xSurface, ySurface, 1),\
										get_rgb_surface(textures->current, xSurface, ySurface, 4));
		SDL_RenderDrawPoint(win->rend, j, win->height / 2 + i);
		ySurface += dySurface;
	}
}

void		draw(t_win *win, t_calculs *calculs, t_textures *textures)
{
	t_dot_2d	dfloor1;
	t_dot_2d	dfloor2;
	t_dot_2d	d1;
	t_dot_2d	d2;
	int			j;
	
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
			d1 = (t_dot_2d){.x = j, .y = win->height / 2 - HEIGHT_WALL / calculs->dist[j]};
			d2 = (t_dot_2d){.x = j, .y = win->height / 2 + HEIGHT_WALL / calculs->dist[j]};
			
			//SDL_SetRenderDrawColor(win->rend, BACK_R, BACK_G, BACK_B, 255);
			//draw_line(win, dfloor2, d1, win->rend);
			draw_sky(win, textures, j);

			draw_wall(win, calculs, textures, j);
			
			SDL_SetRenderDrawColor(win->rend, BACK_R, BACK_G, BACK_B, 255);
			draw_line(win, d2, dfloor1, win->rend);
			
		}
	}
}
