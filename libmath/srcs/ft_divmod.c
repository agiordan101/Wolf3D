/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_divmod.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:24:51 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:24:52 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

void	ft_divmod(double nbr, int *intpart, int *decpart)
{
	if (intpart)
		*intpart = (int)nbr;
	if (decpart)
		*decpart = ft_modulo(nbr, 1);
}
