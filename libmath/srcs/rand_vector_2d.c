/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rand_vector_2d.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:22:29 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 17:47:23 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

t_vector_2d	*rand_vector_2d(void)
{
	t_dot_2d	origin;

	srand(time(0));
	origin = (t_dot_2d){.x = 0, .y = 0};
	return (normalize_vector_2d(new_vector_2d(&origin, rand(), rand())));
}
