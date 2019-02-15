/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rand_dot_2d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:22:44 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:22:45 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

dot_2d	*rand_dot_2d(double xmin, double xmax,\
			double ymin, double ymax)
{
	srand(time(0));
	return (new_dot_2d(xmin + ft__abs(cos(rand())) * (xmax - xmin),\
			ymin + ft__abs(cos(rand())) * (ymax - ymin)));
}
