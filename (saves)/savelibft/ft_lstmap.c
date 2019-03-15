/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 19:33:04 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 19:33:05 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*s;
	t_list	*savelast;

	if (!lst)
		return (NULL);
	if (!(first = f(lst)))
		return (NULL);
	s = first;
	savelast = s;
	lst = lst->next;
	while (lst)
	{
		s = f(lst);
		savelast->next = s;
		savelast = s;
		lst = lst->next;
	}
	return (first);
}
