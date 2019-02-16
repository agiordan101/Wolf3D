/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mag_vector_2d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:23:39 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:33:55 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

double	mag_vector_2d(t_vector_2d vector)
{
	return (ft__sqrt(vector.x * vector.x + vector.y * vector.y, 2));
}
