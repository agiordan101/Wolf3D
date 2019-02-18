/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:23:30 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/17 03:33:42 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/libmath.h"
#include "../libft/libft.h"
#include <stdio.h>

int	main()
{
	/*double x = 3;
	double y = 8.642654645;
	double z = 2.7;
	dot_2d	*d1;
	vector_2d	*v1;
	dot_2d	*d2;

	d1 = new_dot_2d(x, x);
	d2 = new_dot_2d(x, y);
	v1 = new_vector_2d(d1, x, x);
	printf("%lf\n", dist_origin_dot_2d(*d1));
	//printf("p = %p\nx = %lf\ny = %lf\n", d3, d3->x, d3->y);
	del_dot_2d(&d1);
	del_dot_2d(&d2);
	printf("p = %p\n", d1);
	printf("p = %p\n", d2);*/
	printf("%i\n", ft_dtoi_low(6.5));
	printf("%i\n\n", ft_dtoi_up(6.5));
	printf("%i\n", ft_dtoi_low(-1.5));
	printf("%i\n", ft_dtoi_up(-1.5));
	return (0);
}
