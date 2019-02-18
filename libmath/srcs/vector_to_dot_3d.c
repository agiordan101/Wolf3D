/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vector_to_dot_3d.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 21:40:36 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 21:44:37 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_dot_3d	vector_to_dot_3d(t_vector_3d vector)
{
	return ((t_dot_3d){.x = vector.x, .y = vector.y, .z = vector.z});
}
