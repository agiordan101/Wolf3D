/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_power.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:24:02 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:24:18 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

/*
**	Impossible de modulo un double avec l'operateur '%'
*/

double	ft_power(double nbr, double power)
{
	if (nbr < 0)
	{
		if (ft_modulo(power, 1))
			return (0);
		return (ft_power(-nbr, power) *\
				((int)power % 2 ? -1 : 1));
	}
	return (exp(power * log(nbr)));
}
