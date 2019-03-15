/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 17:19:16 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 17:19:16 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(str = ft_strnew(ft_strlen((char *)s))))
		return (NULL);
	i = 0;
	while (i < ft_strlen((char *)s))
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
