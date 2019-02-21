/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_filereplace.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gal <gal@student.le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/12 17:08:16 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 16:54:49 by gal         ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	ft_filereplace(char *file, char *target, char *replace)
{
	char	*line;
	int		fdrd;
	int		fdwr;
	int		ret;

	if (((fdrd = open(file, O_RDONLY)) == -1) ||\
		(fdwr = open(ft_strcat(file, "_replace"), O_CREAT | O_WRONLY,\
								S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
		return (1);
	line = NULL;
	while ((ret = get_next_line(fdrd, &line)) == 1)
	{
		line = ft_strreplace(line, target, replace);
		ft_putendl_fd(line, fdwr);
	}
	return (ret == -1 ? 1 : 0);
}
