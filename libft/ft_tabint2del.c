/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tabint2del.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/10 18:54:01 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 16:41:28 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabint2del(int ***tab, size_t len)
{
	size_t	i;

	i = -1;
	if (!tab || !(*tab))
		return ;
	while (++i < len)
		ft_tabintdel(&((*tab)[i]));
	free(*tab);
	*tab = NULL;
}
