/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   new_vector_3d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:23:00 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:23:02 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

vector_3d	*new_vector_3d(dot_3d *origin, double x,\
					double y, double z)
{
	vector_3d	*vector;

	if (!(vector = (vector_3d *)malloc(sizeof(vector_3d))))
		return (NULL);
	*vector = (vector_3d){.x = x, .y = y, .z = z};
	if (origin)
		vector->origin = (dot_3d){.x = origin->x, .y = origin->y, .z = origin->z};
	set_mag_vector_3d(vector);
	return (vector);
}
