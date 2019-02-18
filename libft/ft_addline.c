/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_addline.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 21:02:28 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/24 17:23:18 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_addline(char **tab, char *line, size_t length)
{
	char	**newtab;
	size_t	i;

	newtab = (char **)malloc(sizeof(char *) * (length + 1));
	i = -1;
	while (++i < length)
	{
		newtab[i] = ft_strdup(tab[i]);
		ft_strdel(tab + i);
	}
	if (!tab)
		free(tab);
	newtab[i] = ft_strdup(line);
	ft_strdel(&line);
	return (newtab);
}
