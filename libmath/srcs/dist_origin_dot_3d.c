/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dist_origin_dot_3d.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:25:08 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:25:10 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

double	dist_origin_dot_3d(dot_3d dot)
{
	return (ft__sqrt(dot.x * dot.x + dot.y * dot.y + dot.z * dot.z, 2));
}
