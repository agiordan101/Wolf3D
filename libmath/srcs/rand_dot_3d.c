/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rand_dot_3d.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:22:35 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:22:37 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

dot_3d	*rand_dot_3d(double min, double max)
{
	srand(time(0));
	return (new_dot_3d(min + ft__abs(cos(rand())) * (max - min),\
			min + ft__abs(cos(rand())) * (max - min),\
			min + ft__abs(cos(rand())) * (max - min)));
}
