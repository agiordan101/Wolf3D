/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mag_vector_3d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:23:35 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:50:02 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

double	mag_vector_3d(t_vector_3d vector)
{
	return (ft__sqrt(vector.x * vector.x + vector.y * vector.y +\
					vector.z * vector.z, 2));
}
