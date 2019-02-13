/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 20:53:56 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 20:53:57 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule, const char *aiguille)
{
	int	i;

	if (!aiguille[0])
		return ((char *)meule);
	while (*meule)
	{
		i = 0;
		while (meule[i] - aiguille[i] == 0)
		{
			i++;
			if (!aiguille[i])
				return ((char *)meule);
		}
		meule++;
	}
	return (NULL);
}
