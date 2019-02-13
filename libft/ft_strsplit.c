/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 20:32:08 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 20:32:09 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlength(const char *str, char c, int i)
{
	int count;

	count = 0;
	while (str[i + count] != c && str[i + count])
		count++;
	return (count);
}

static int	ft_countwords(const char *s, char c)
{
	int	count;
	int	first;

	count = 0;
	first = 1;
	while (*s)
	{
		if (*s == c)
			first = 1;
		else if (first == 1)
		{
			first = 0;
			count++;
		}
		s++;
	}
	return (count);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		words;

	if (!s || !c)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1))))
		return (NULL);
	tab[ft_countwords(s, c)] = NULL;
	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			if (!(tab[words] = ft_strnew(ft_wordlength(s, c, i))))
				return (NULL);
		j = 0;
		while (s[i] != c && s[i])
			tab[words][j++] = s[i++];
		words++;
	}
	return (tab);
}
