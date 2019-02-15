/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   new_vector_2d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:23:06 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/14 20:17:22 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

vector_2d	*new_vector_2d(dot_2d *origin, double x, double y)
{
	vector_2d	*vector;

	if (!(vector = (vector_2d *)malloc(sizeof(vector_2d))))
		return (NULL);
	*vector = (vector_2d){.x = x, .y = y};
	if (origin)
		vector->origin = (dot_2d){.x = origin->x, .y = origin->y};
	set_mag_vector_2d(vector);
	return (vector);
}
