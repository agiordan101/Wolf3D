/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   new_vector_3d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:23:00 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:45:37 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_vector_3d	*new_vector_3d(t_dot_3d *origin, double x, double y, double z)
{
	t_vector_3d	*vector;

	if (!(vector = (t_vector_3d *)malloc(sizeof(t_vector_3d))))
		return (NULL);
	*vector = (t_vector_3d){.x = x, .y = y, .z = z};
	if (origin)
		vector->origin = (t_dot_3d){.x = origin->x, .y = origin->y,\
													.z = origin->z};
	set_mag_vector_3d(vector);
	return (vector);
}
