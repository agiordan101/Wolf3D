/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sub_vector_3d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:21:36 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:47:12 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_vector_3d	*sub_vector_3d(t_vector_3d vector1, t_vector_3d vector2)
{
	t_dot_3d	origin;

	origin = (t_dot_3d){.x = vector1.x, .y = vector1.y,\
						.z = vector1.z};
	return (new_vector_3d(&origin, vector1.x - vector2.x,\
					vector1.y - vector2.y,\
					vector1.z - vector2.z));
}
