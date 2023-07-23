#include <stdio.h>
#include "../vector.h"

void	print_vector(t_vector *v)
{
	printf("vector info\nx: %lf, y: %lf, z: %lf\n", v->x, v->y, v->z);
}