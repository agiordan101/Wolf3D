/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 16:01:05 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/16 16:01:09 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *first)
{
	size_t count;

	if (!first)
		return (0);
	count = 1;
	while (first->next)
	{
		first = first->next;
		count++;
	}
	return (count);
}
