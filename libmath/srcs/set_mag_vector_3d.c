/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_mag_vector_3d.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:21:48 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:46:51 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_vector_3d	*set_mag_vector_3d(t_vector_3d *vector)
{
	vector->mag = ft__sqrt(vector->x * vector->x +\
				vector->y * vector->y +\
				vector->z * vector->z, 2);
	return (vector);
}
