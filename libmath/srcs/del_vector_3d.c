/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   del_vector_3d.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:25:27 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:25:29 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

void	del_vector_3d(vector_3d **vector)
{
	if (!vector)
		return ;	
	free(*vector);
	*vector = NULL;
}
