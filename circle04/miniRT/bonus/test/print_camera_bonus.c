#include <stdio.h>
#include "test.h"

void	print_camera(t_camera *t)
{
	printf("camera info\nposition vector: ");
	print_vector(t->position);
	printf("normalized vector: ");
	print_vector(t->normal_vector);
	printf("fov: %lf\n", t->fov);
}