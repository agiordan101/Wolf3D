/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 20:39:44 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 20:39:46 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_nbrlen(n);
	if (!(str = ft_strnew(1 + i)))
		return (NULL);
	if (n == -2147483648)
	{
		str[i--] = '8';
		n = -214748364;
	}
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (i > 0)
	{
		str[i--] = n % 10 + '0';
		n = (n - n % 10) / 10;
	}
	if (str[0] == '-')
		return (str);
	else
		return (ft_strsub(str, 1, ft_strlen(str + 1)));
}
