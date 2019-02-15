/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_mag_vector_3d.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:21:48 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:21:50 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

vector_3d	*set_mag_vector_3d(vector_3d *vector)
{
	vector->mag = ft__sqrt(vector->x * vector->x +\
				vector->y * vector->y +\
				vector->z * vector->z, 2);
	return (vector);
}
