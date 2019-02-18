/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 15:29:30 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 15:29:33 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meule, const char *aiguille, size_t n)
{
	int		i;
	size_t	k;
	size_t	savek;

	if (!aiguille[0])
		return ((char *)meule);
	k = 0;
	while (*meule && k < n)
	{
		savek = k;
		i = 0;
		while (meule[i] - aiguille[i] == 0 && k < n)
		{
			i++;
			k++;
			if (!aiguille[i])
				return ((char *)meule);
		}
		k = savek;
		k++;
		meule++;
	}
	return (NULL);
}
