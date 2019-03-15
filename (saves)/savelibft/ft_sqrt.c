/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/04 16:40:17 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 16:45:40 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int racine;

	racine = 0;
	while (racine * racine <= nb)
	{
		if (racine * racine == nb)
			return (racine);
		racine++;
	}
	return (0);
}
