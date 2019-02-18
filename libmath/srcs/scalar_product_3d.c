/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scalar_product_3d.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:22:01 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:34:30 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

double	scalar_product_3d(t_vector_3d vector1, t_vector_3d vector2)
{
	return (vector1.x * vector2.x + vector1.y * vector2.y +\
		vector1.z * vector2.y);
}
