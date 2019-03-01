/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pythagore.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/01 16:23:21 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 17:06:46 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"
#include "stdio.h"

double	ft_pythagore(double *hypo, double *c1, double *c2)
{
	printf("\n");
	if (*hypo < 0 && *c1 >= 0 && *c2 >= 0)
		return (*hypo = ft__sqrt(*c1 * *c1 + *c2 * *c2, 2));
	else if (*c1 < 0 && *hypo >= 0 && *c2 >= 0)
		return (*c1 = ft__sqrt(*hypo * *hypo - *c2 * *c2, 2));
	else if (*c2 < 0 && *hypo >= 0 && *c1 >= 0)
		return (*c2 = ft__sqrt(*hypo * *hypo - *c1 * *c1, 2));
	else
		return (-1);
}

