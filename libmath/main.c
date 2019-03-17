/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:23:30 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/17 20:21:36 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "include/libmath.h"
#include "../libft/libft.h"
#include <stdio.h>

int	main(void)
{
	double *a;
	double *b;
	double *h;

	printf("sqrt() = %lf\n", ft__sqrt(15.65, 8));
	printf("FIN DU SQRT");
	a = (double *)malloc(sizeof(double));
	b = (double *)malloc(sizeof(double));
	h = (double *)malloc(sizeof(double));
	a = NULL;
	*b = 3;
	*h = 3.605551;
	printf("%lf\n", ft_pythagore(h, a, b));
	return (0);
}
