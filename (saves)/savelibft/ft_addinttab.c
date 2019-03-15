/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_addinttab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 20:16:36 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 23:35:58 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		**ft_addinttab(int **tab, size_t nline, int *line, size_t len)
{
	int		**newtab;
	size_t	i;
	size_t	j;

	newtab = (int **)malloc(sizeof(int *) * (nline + 1));
	i = 0;
	while (i < nline)
	{
		newtab[i] = (int *)malloc(sizeof(int) * len);
		j = 0;
		while (j < len)
		{
			newtab[i][j] = tab[i][j];
			j++;
		}
		i++;
	}
	j = 0;
	while (j < len)
	{
		newtab[i][j] = line[j];
		j++;
	}
	return (newtab);
}
