/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_factorial.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 19:24:28 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 19:24:30 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

double	ft_factorial(int nbr)
{
	if (nbr == 0)
		return (1);
	else if (nbr < 0 || nbr % 1)
		return (-1);
	return (ft_factorial(nbr - 1) * nbr);
}
