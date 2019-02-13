/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_catinttab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:46:16 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 17:58:03 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_catinttab(int *t1, size_t size1, int *t2, size_t size2)
{
	int		*newtab;
	int		i;
	int		j;

	if (!(newtab = (int*)ft_memalloc(size1 + size2)))
		return (NULL);
	i = 0;
	while (i < (int)size1)
	{
		newtab[i] = t1[i];
		i++;
	}
	j = 0;
	while (j < (int)size2)
		newtab[i++] = t2[j++];
	return (newtab);
}
