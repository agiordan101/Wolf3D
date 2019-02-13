/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_stristr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 17:07:53 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 18:41:11 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_stristr(char *str, char *tofind)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i + j] == tofind[j] || !tofind[j])
			if (!tofind[j++])
				return (i);
	}
	return (-1);
}
