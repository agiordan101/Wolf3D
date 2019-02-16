/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_mag_vector_2d.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:21:54 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:46:46 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_vector_2d	*set_mag_vector_2d(t_vector_2d *vector)
{
	vector->mag = ft__sqrt(vector->x * vector->x +\
				vector->y * vector->y, 2);
	return (vector);
}
