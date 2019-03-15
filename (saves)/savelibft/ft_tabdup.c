/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tabdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 14:48:04 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/07 14:48:06 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	char	**newtab;
	size_t	len;
	size_t	i;

	i = -1;
	len = ft_tablen(tab);
	if (!(newtab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	newtab[len] = NULL;
	while (++i < len)
		if (!(newtab[i] = ft_strnew(ft_strlen(tab[i]))))
			return (NULL);
	ft_tabcpy(newtab, tab);
	return (newtab);
}
