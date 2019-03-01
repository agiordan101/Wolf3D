/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pythagore.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/01 16:23:21 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 17:34:43 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

/*
**	Si UN SEUL pointeur est null, renvois la valeur qui lui correspont par
**														rapport aux 2  autres.
**	Sinon :
**	Remplis le pointeur comportant une valeur negative par rapport aux 2 autres,
**														si elles ne le sont pas.
*/

double	ft_pythagore(double *hypo, double *c1, double *c2)
{
	if (!hypo && c1 && c2)
		return (ft__sqrt(*c1 * *c1 + *c2 * *c2, 2));
	if (hypo && !c1 && c2)
		return (ft__sqrt(*hypo * *hypo - *c2 * *c2, 2));
	if (hypo && c1 && !c2)
		return (ft__sqrt(*hypo * *hypo - *c1 * *c1, 2));
	if (*hypo < 0 && *c1 >= 0 && *c2 >= 0)
		return (*hypo = ft__sqrt(*c1 * *c1 + *c2 * *c2, 2));
	if (*hypo >= 0 && *c1 < 0 && *c2 >= 0)
		return (*c1 = ft__sqrt(*hypo * *hypo - *c2 * *c2, 2));
	if (*hypo >= 0 && *c1 >= 0 && *c2 < 0)
		return (*c2 = ft__sqrt(*hypo * *hypo - *c1 * *c1, 2));
	return (-1);
}

