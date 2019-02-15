/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scalar_product_2d.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:22:10 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:22:12 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libmath.h"

double	scalar_product_2d(vector_2d vector1, vector_2d vector2)
{
	return (vector1.x * vector2.x + vector1.y * vector2.y);
}
