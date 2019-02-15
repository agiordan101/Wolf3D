/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_countnumbers.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 20:23:39 by gmonacho     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/15 15:08:21 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_countnumbers(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i++]))
		{
			nb++;
			while (ft_isdigit(str[i]) && str[i])
				i++;
		}
	}
	return (nb);
}
