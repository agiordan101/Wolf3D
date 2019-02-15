/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rand_vector_3d.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:22:17 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:22:20 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

vector_3d	*rand_vector_3d()
{
	dot_3d	origin;

	srand(time(0));
	origin = (dot_3d){.x = 0, .y = 0, .z = 0};
	return (normalize_vector_3d(new_vector_3d(\
		&origin, rand(), rand(), rand())));
	/*angle = ft_modulo(rand(), 2 * PI);
	x = cos(angle);
	y = sin(angle);
	return (new_vector_3d(origin, cos(angle), sin(angle),\
			ft__sqrt(1 - x * x - y * y, 2)));*/
}
