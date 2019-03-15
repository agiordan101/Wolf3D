/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 19:47:45 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 19:47:46 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len;
	size_t i;

	len = ft_strlen(dest);
	i = 0;
	while (src[i] && i < n)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}
