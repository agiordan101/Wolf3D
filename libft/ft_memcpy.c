/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 20:47:36 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 20:47:38 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*castsrc;
	char	*castdest;

	castsrc = (char *)src;
	castdest = (char *)dest;
	i = 0;
	while (i < n)
	{
		castdest[i] = castsrc[i];
		i++;
	}
	return (castdest);
}
