/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sorttab.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/22 18:45:48 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/22 18:45:50 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_sorttab(int *tab, size_t length, int (*f)(int a, int b))
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < length)
	{
		j = i;
		while (j < length)
		{
			if (!(f(tab[i], tab[j])))
				ft_swapint(tab + i, tab + j);
			j++;
		}
		i++;
	}
}
