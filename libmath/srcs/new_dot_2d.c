/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   new_dot_2d.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:23:19 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:23:20 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

dot_2d	*new_dot_2d(double x, double y)
{
	dot_2d	*dot;

	if (!(dot = (dot_2d *)malloc(sizeof(dot_2d))))
		return (NULL);
	*dot = (dot_2d){.x = x, .y = y};
	return (dot);
}
