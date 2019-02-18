/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dot_to_vector_3d.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 21:40:34 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 21:43:20 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_vector_3d	dot_to_vector_3d(t_dot_3d dot)
{
	return ((t_vector_3d){.origin = (t_dot_3d){.x = 0, .y = 0, .z = 0},\
							.x = dot.x, .y = dot.y, .z = dot.z});
}
