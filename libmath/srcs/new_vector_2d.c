/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   new_vector_2d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:23:06 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:45:12 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_vector_2d	*new_vector_2d(t_dot_2d *origin, double x, double y)
{
	t_vector_2d	*vector;

	if (!(vector = (t_vector_2d *)malloc(sizeof(t_vector_2d))))
		return (NULL);
	*vector = (t_vector_2d){.x = x, .y = y};
	if (origin)
		vector->origin = (t_dot_2d){.x = origin->x, .y = origin->y};
	set_mag_vector_2d(vector);
	return (vector);
}
