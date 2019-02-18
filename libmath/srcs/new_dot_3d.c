/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   new_dot_3d.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:23:19 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:44:56 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_dot_3d	*new_dot_3d(double x, double y, double z)
{
	t_dot_3d	*dot;

	if (!(dot = (t_dot_3d *)malloc(sizeof(t_dot_3d))))
		return (NULL);
	*dot = (t_dot_3d){.x = x, .y = y, .z = z};
	return (dot);
}
