/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_newlist.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/19 18:30:27 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/19 18:30:29 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_newlist(size_t size)
{
	t_list	*list;
	size_t	i;

	if (!size)
		return (NULL);
	list = ft_lstnew(NULL, 0);
	i = 1;
	while (i++ < size)
		ft_lstadd(&list, ft_lstnew(NULL, 0));
	return (list);
}
