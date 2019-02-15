/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sub_vector_3d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:21:36 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:21:39 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

vector_3d	*sub_vector_3d(vector_3d vector1, vector_3d vector2)
{
	dot_3d	origin;

	origin = (dot_3d){.x = vector1.x, .y = vector1.y,\
						.z = vector1.z};
	return (new_vector_3d(&origin, vector1.x - vector2.x,\
					vector1.y - vector2.y,\
					vector1.z - vector2.z));
}
