/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   surface.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/12 18:56:07 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/13 15:10:25 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Texture     *create_t_from_s(SDL_Surface *surface, SDL_Renderer *rend)
{
    SDL_Texture *texture;

    if (!(texture = SDL_CreateTextureFromSurface(rend, surface)))
        return (NULL);
    return (texture);
}