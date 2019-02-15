/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libmath.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <agiordan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:31:57 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/14 20:19:41 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBMATH_H
# define LIBMATH_H
# define PI 3.141592653589793238462643383279502884167169399375109749445923078964
# define E 2.718281801

# include <stdlib.h>
# include <math.h> //Seulement pour ln(x), e(x) et rand()
# include <time.h> //Seulement pour time

typedef struct	dot_2d
{
	double	x;
	double	y;
}				dot_2d;

typedef struct	vector_2d
{
	dot_2d	origin;
	double	mag;
	double	x;
	double	y;
}				vector_2d;

typedef struct	dot_3d
{
	double	x;
	double	y;
	double	z;
}				dot_3d;

typedef struct	vector_3d
{
	dot_3d	origin;
	double	mag;
	double	x;
	double	y;
	double	z;
}				vector_3d;

/*
**	Generics fonctions
*/

double		ft__abs(double nbr);
int			ft_dtoi_low(double nbr);
int			ft_dtoi_up(double nbr);
double		ft__sqrt(double nbr, int power);
double		ft_square(double nbr);
double		ft_power(double nbr, double power);
double		ft_exp(int nbr);
double		ft_factorial(int nbr);
double		ft_radtod(double nbr);
double		ft_dtorad(double nbr);
void		ft_divmod(double nbr, int *intpart, int *decpart);
double		ft_modulo(double nbr, double mod);


/*
**	Dots functions 2d/3d
**	del_dot ont 2* pour que dot ne conserve pas l'adresse supprimee
*/

dot_2d		*new_dot_2d(double x, double y);
void		del_dot_2d(dot_2d **dot);
double		dist_dot_2d(dot_2d d1, dot_2d d2);
double		dist_origin_dot_2d(dot_2d dot);
dot_2d		*rand_dot_2d(double xmin, double xmax, double ymin, double ymax);

dot_3d		*new_dot_3d(double x, double y, double z);
void		del_dot_3d(dot_3d **dot);
double		dist_dot_3d(dot_3d d1, dot_3d d2);
double		dist_origin_dot_3d(dot_3d dot);
dot_3d		*rand_dot_3d(double min, double max);

/*
**	Vectors *functions 2d/3d
**	new_vector portent l'adresse d'un dot car on doit pouvoir passer null
*/

vector_2d	*new_vector_2d(dot_2d *origin, double x, double y);
void		del_vector_2d(vector_2d **vector);
vector_2d	*set_mag_vector_2d(vector_2d *vector);
double		mag_vector_2d(vector_2d vector);
vector_2d	*add_vector_2d(vector_2d vector1, vector_2d vector2);
vector_2d	*sub_vector_2d(vector_2d vector1, vector_2d vector2);
double		scalar_product_2d(vector_2d vector1, vector_2d vector2);
vector_2d	*normalize_vector_2d(vector_2d *vector);
vector_2d	*rand_vector_2d();

vector_3d	*new_vector_3d(dot_3d *origin, double x, double y, double z);
void		del_vector_3d(vector_3d **vector);
vector_3d	*set_mag_vector_3d(vector_3d *vector);
double		mag_vector_3d(vector_3d vector);
vector_3d	*add_vector_3d(vector_3d vector1, vector_3d vector2);
vector_3d	*sub_vector_3d(vector_3d vector1, vector_3d vector2);
double		scalar_product_3d(vector_3d vector1, vector_3d vector2);
vector_3d	*vector_product(vector_3d vector1, vector_3d vector2);
vector_3d	*normalize_vector_3d(vector_3d *vector);
vector_3d	*rand_vector_3d();

#endif
