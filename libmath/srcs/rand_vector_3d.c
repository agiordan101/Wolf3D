/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rand_vector_3d.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:22:17 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:52:11 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_vector_3d	*rand_vector_3d(void)
{
	t_dot_3d	origin;

	srand(time(0));
	origin = (t_dot_3d){.x = 0, .y = 0, .z = 0};
	return (normalize_vector_3d(new_vector_3d(\
		&origin, rand(), rand(), rand())));
}
