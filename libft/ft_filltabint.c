/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_filltabint.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 14:24:58 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/08 19:10:00 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_filltabint(int **tab, size_t len, int nbr)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		(*tab)[i] = nbr;
		i++;
	}
}
