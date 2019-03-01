/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:23:30 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/01 17:06:48 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/libmath.h"
#include "../libft/libft.h"
#include <stdio.h>

int	main()
{
	double *a;
	double *b;
	double *h;

	printf("sqrt() = %lf\n", ft__sqrt(15.65, 8));
	printf("FIN DU SQRT");
	a = (double *)malloc(sizeof(double));
	b = (double *)malloc(sizeof(double));
	h = (double *)malloc(sizeof(double));
	*a = 2;
	*b = -1;
	*h = 3.605551;
	printf("%lf\n", ft_pythagore(h, a, b));
	printf("%lf\n", *b);
	return (0);
}
