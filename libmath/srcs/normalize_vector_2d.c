/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   normalize_vector_2d.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:22:55 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:45:54 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_vector_2d	*normalize_vector_2d(t_vector_2d *vector)
{
	double	mag;

	mag = mag_vector_2d(*vector);
	vector->x = vector->x / mag;
	vector->y = vector->y / mag;
	vector->mag = 1;
	return (vector);
}
