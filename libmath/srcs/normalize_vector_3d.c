/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   normalize_vector_3d.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:22:49 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:46:04 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_vector_3d	*normalize_vector_3d(t_vector_3d *vector)
{
	double	mag;

	mag = mag_vector_3d(*vector);
	vector->x = vector->x / mag;
	vector->y = vector->y / mag;
	vector->z = vector->z / mag;
	vector->mag = 1;
	return (vector);
}
