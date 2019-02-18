/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_catinttab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 17:46:16 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 17:01:23 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		*ft_catinttab(int *tab1, size_t l1, int *tab2, size_t l2)
{
	int	*newtab;
	int	i;
	int	j;

	if (!tab1)
		l1 = 0;
	if (!tab2)
		l2 = 0;
	if (!(newtab = (int*)ft_memalloc(sizeof(int) * (l1 + l2))))
		return (NULL);
	i = -1;
	if (tab1)
		while (++i < (int)l1)
			newtab[i] = tab1[i];
	j = 0;
	if (tab2)
		while (j < (int)l2)
			newtab[i++] = tab2[j++];
	return (newtab);
}
