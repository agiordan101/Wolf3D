/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_catinttab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:46:16 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 15:15:14 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_catinttab(int *tab1, size_t len1, int *tab2, size_t len2)
{
	int	*newtab;
	int	i;
	int	j;

	if (!tab1)
		return (tab2);
	if (!tab2)
		return (tab1);
	if (!(newtab = (int*)ft_memalloc(sizeof(int) * (len1 + len2))))
		return (NULL);
	i = -1;
	while (++i < (int)len1)
		newtab[i] = tab1[i];
	j = 0;
	while (j < (int)len2)
		newtab[i++] = tab2[j++];
	return (newtab);
}
