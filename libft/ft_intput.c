/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_intput.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:34:15 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 15:10:10 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_intput(int *tab, size_t len)
{
	int	i;

	i = 0;
	while (i < (int)len)
		ft_putnbr(tab[i++]);
}
