/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:58:06 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 17:05:41 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*casts1;
	unsigned char	*casts2;
	size_t			i;

	casts1 = (unsigned char *)s1;
	casts2 = (unsigned char *)s2;
	i = 0;
	while (i < n && casts1[i] == casts2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	else
		return (casts1[i] - casts2[i]);
}
