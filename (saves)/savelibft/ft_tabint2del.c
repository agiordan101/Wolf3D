/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tabint2del.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 18:54:01 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/13 22:40:17 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabint2del(int ***tab, size_t len)
{
	size_t	i;

	i = -1;
	if (!tab || !(*tab))
	{
		while (++i < len)
			ft_tabintdel(&((*tab)[i]));
		free(*tab);
		*tab = NULL;
	}
}
