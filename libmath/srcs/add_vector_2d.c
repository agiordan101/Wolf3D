/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add_vector_2d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 17:12:43 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:40:12 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_vector_2d	*add_vector_2d(t_vector_2d vector1, t_vector_2d vector2)
{
	t_dot_2d	origin;

	origin = (t_dot_2d){.x = vector1.x, .y = vector1.y};
	return (new_vector_2d(&origin, vector1.x + vector2.x,\
					vector1.y + vector2.y));
}
