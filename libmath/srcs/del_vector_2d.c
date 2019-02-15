/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   del_vector_2d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:25:30 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:25:32 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

void	del_vector_2d(vector_2d **vector)
{
	if (!vector)
		return ;	
	free(*vector);
	*vector = NULL;
}
