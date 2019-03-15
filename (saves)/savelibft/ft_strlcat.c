/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 19:53:04 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 19:00:58 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	lendest;
	size_t	lensrc;

	i = 0;
	lendest = ft_strlen(dest);
	lensrc = ft_strlen((char *)src);
	while (n > lendest + i + 1 && src[i])
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	if (n < lendest)
		return (lensrc + n);
	else
		return (lensrc + lendest);
}
