/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tabnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 16:57:21 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/07 17:13:37 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabnew(size_t nline, size_t lline)
{
	char	**tab;
	size_t	i;

	tab = (char **)malloc(sizeof(char *) * (nline + 1));
	tab[nline] = NULL;
	i = -1;
	while (++i < nline)
		tab[i] = ft_strnew((int)lline);
	return (tab);
}
