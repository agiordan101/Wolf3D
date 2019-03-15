/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memrcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 20:47:36 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 20:47:38 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*castsrc;
	char	*castdest;

	castsrc = (char *)src;
	castdest = (char *)dest;
	i = n;
	while (i > 0)
	{
		i--;
		castdest[i] = castsrc[i];
	}
	return (castdest);
}
