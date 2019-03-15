/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmonacho <gmonacho@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 21:28:54 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/07 20:42:45 by gmonacho    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1 && s2)
	{
		while (*s1 == *s2 && *s1 && *s2)
		{
			s1++;
			s2++;
		}
		return ((unsigned char)(*s1) - (unsigned char)(*s2));
	}
	else
		return (-1);
}
