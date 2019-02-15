/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strreplace.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 17:08:22 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 15:14:57 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char *target, char *replace)
{
	char	*left;
	char	*right;
	int		ifind;

	while ((ifind = ft_stristr(str, target)) != -1)
	{
		left = ft_strsub(str, 0, ifind);
		right = ft_strsub(str, ifind + ft_strlen(target),\
			ft_strlen(str) - ifind - ft_strlen(target));
		str = ft_strnew(ft_strlen(left) +\
			ft_strlen(replace) + ft_strlen(right));
		str = ft_strcpy(str, left);
		str = ft_strcat(str, replace);
		str = ft_strcat(str, right);
		if (ft_stristr(ft_strcat(left, right), target) == -1)
			return (str);
	}
	return (str);
}
