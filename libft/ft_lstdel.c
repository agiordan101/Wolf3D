/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 19:01:14 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 19:01:18 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *s;
	t_list *next;

	s = *alst;
	while (s)
	{
		next = s->next;
		ft_lstdelone(&s, del);
		s = next;
	}
	*alst = NULL;
}
