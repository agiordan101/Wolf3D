/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_modulo.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:24:23 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:24:25 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

double	ft_modulo(double nbr, double mod)
{
	return (nbr - (int)(nbr / mod) * mod -\
			(mod < 0 ? mod : 0));
}
