/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printtabl.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 18:56:42 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 19:15:36 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtabl(char **tab)
{
	int	i;
	int	len;

	len = ft_tablen(tab);
	i = -1;
	while (++i < len)
		ft_putendl(tab[i]);
	ft_putchar('\n');
}
