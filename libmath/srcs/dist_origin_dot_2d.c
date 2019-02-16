/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dist_origin_dot_2d.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:25:18 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:35:00 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

double	dist_origin_dot_2d(t_dot_2d dot)
{
	return (ft__sqrt(dot.x * dot.x + dot.y * dot.y, 2));
}
