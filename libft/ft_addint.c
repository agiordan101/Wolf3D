/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_addint.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gal <gal@student.le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 18:19:54 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 16:52:50 by gal         ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	*ft_addint(int *tab, int nbr, size_t length)
{
	int		*newtab;
	size_t	i;

	if(!(newtab = (int *)malloc(sizeof(int) * (length + 1))))
		return (NULL);
	i = -1;
	while (++i < length)
		newtab[i] = tab[i];
	newtab[i] = nbr;
	return (newtab);
}
