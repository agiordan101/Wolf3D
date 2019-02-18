/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tabcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 14:48:04 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/07 14:48:06 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcpy(char **dest, char **src)
{
	size_t	len;
	size_t	i;

	i = -1;
	if (!dest || !src || (len = ft_tablen(src)) != (size_t)ft_tablen(dest))
		return (NULL);
	while (++i < len)
	{
		if (ft_strlen(src[i]) != ft_strlen(dest[i]))
			return (NULL);
		ft_strcpy(dest[i], src[i]);
	}
	return (dest);
}
