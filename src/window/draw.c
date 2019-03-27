/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/18 16:24:13 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 19:11:19 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

static int		get_rgb_surface(SDL_Surface *surface,
								double x, double y, int elem)
{
	int			bpp;
	Uint32		*pixel;

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

static void		draw_wall(t_win *win, t_calculs *calculs,\
							t_textures *textures, int j)
{
	double		y_surface;
	double		x_surface;
	double		dy_surface;
	double		h;

	h = HEIGHT_WALL / calculs->dist[j];
	textures->current = win->textures_mode == 3 ? textures->tabdev\
	[calculs->orientation[j] - 1] : textures->tab[calculs->orientation[j] - 1];
	y_surface = 0;
	x_surface = win->calculs.xray[j] * textures->current->w;
	dy_surface = textures->current->h / (2 * h);
	calculs->i = (int)(-h);
	while (++(calculs->i) < (int)h)
	{
		if (calculs->i > -win->width / 2 && calculs->i < win->width / 2)
		{
			SDL_SetRenderDrawColor(win->rend,
				get_rgb_surface(textures->current, x_surface, y_surface, 2),\
				get_rgb_surface(textures->current, x_surface, y_surface, 3),\
				get_rgb_surface(textures->current, x_surface, y_surface, 1),\
				get_rgb_surface(textures->current, x_surface, y_surface, 4));
			SDL_RenderDrawPoint(win->rend, j, win->height / 2 + calculs->i);
		}
		y_surface += dy_surface;
	}
}

void			draw(t_win *win, t_calculs *calculs, t_textures *textures)
{
	t_dot_2d	dfloor;
	t_dot_2d	dlow;
	int			j;

	SDL_RenderCopy(win->rend, win->textures.sky, NULL,\
													&(win->textures.skyrect));
	dfloor.y = win->height;
	j = -1;
	while (++j < win->width)
	{
		dfloor.x = j;
		dlow = (t_dot_2d){.x = j, .y = win->height / 2 +\
				(calculs->dist[j] == -1 ? 0 : HEIGHT_WALL / calculs->dist[j])};
		if (calculs->dist[j] != -1)
			draw_wall(win, calculs, textures, j);
		SDL_SetRenderDrawColor(win->rend, BACK_R, BACK_G, BACK_B, 255);
		draw_line(win, dlow, dfloor, win->rend);
	}
}
