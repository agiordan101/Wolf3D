/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 20:06:45 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 20:06:46 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = (int)ft_strlen((char *)s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (!(s[i]))
		return (ft_strnew(0));
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > i)
		j--;
	j++;
	if ((str = ft_strnew(j - i)) == NULL)
		return (NULL);
	str = ft_strsub(s, i, j - i);
	return (str);
}
