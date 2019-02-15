
#include "libmath.h"

vector_2d	*add_vector_2d(vector_2d vector1, vector_2d vector2)
{
	dot_2d	origin;

	origin = (dot_2d){.x = vector1.x, .y = vector1.y};
	return (new_vector_2d(&origin, vector1.x + vector2.x,\
					vector1.y + vector2.y));
}
