/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sum_x.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/16 19:26:35 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/16 23:49:29 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "wolf3d.h"

int		sum_x(t_map *map, int iwanted)
{
	int	i;
	int	sum_x;

	i = 0;
	sum_x = 0;
	while (i < iwanted)
		sum_x += map->len_x[i++];
	return (sum_x);
}